#include "auth/SessionManager.hpp"
#include "auth/Filling.hpp"
#include "roles/Admin.hpp"
#include "config/ConfigPaths.hpp"
#include "config/AdminConfig.hpp"
#include "infrastructures/FileSystem.hpp"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
using namespace std;
using namespace admin_namespace;
using json = nlohmann::json;

// Implementation of overrided fucntions
void admin_namespace::SessionManager::logout()
{
    save_session();
    delete this->_current_admin;
    this->_current_admin = nullptr;
    this->setAdminID(-1);
    this->_status = SessionStatus::ANONYMOUS;
}

void admin_namespace::SessionManager::load_session(string name)
{
    if (filling::Auth<SessionManager>::sessionExists(name))
    {
        auto file = filling::Auth<SessionManager>::sessionFile(name);
        ifstream reader(file);
        if (!reader.is_open())
        {
            throw runtime_error("file opening error :(");
        }
        json j = json::parse(reader);
        j.get_to(*this);
        reader.close();
    }
    else
    {
        throw runtime_error("session doesn't exists :(");
    }
}
void admin_namespace::SessionManager::save_session()
{
    auto file = filling::Auth<SessionManager>::sessionFile(this->currentAdmin()->getName());
    if (file != "")
    {
        ofstream writer(file);
        json j = *this;
        writer << j;
        writer.close();
    }
    else
    {
        throw runtime_error("session doen't exists :(");
    }
}

bool admin_namespace::SessionManager::login(string name, string password)
{
    if (filling::Auth<SessionManager>::sessionExists(name))
    {
        load_session(name);
        if (this->currentAdmin()->checkPassword(password))
        {
            this->setLastLogin(time(0));
            this->setStatus(SessionStatus::AUTHENTICATED);
            return 1;
        }
        else
        {
            this->logout();
            cerr << "Wrong Password :(" << endl;
            return 0;
        }
    }
    else
    {
        cerr << "There isn't any Admin Session with specified name :(" << endl;
        return 0;
    }
}

// if ther wan't any admin , at begin of the program one should be created
bool SessionManager::isThereAnyAdmin()
{
    auto dir = config::ConfigPaths::instance().d_admin_sessions;
    if (FileSystem::isEmpty(dir))
        return false;
    else
        return true;
}

bool SessionManager::sign_in(string name, string lastname, string password)
{
    Admin *temp = new Admin(config::AdminConfig::instance().getLastIDandIncrease(), name, lastname, "");
    temp->setPassword(password);
    instance().setCurrentAdmin(temp);
    instance().setAdminID(temp->getID());
    instance().setCreatedAT(time(0));
    instance().setStatus(SessionStatus::AUTHENTICATED);
    instance().save_session();
    instance().logout();
    return true; // using try catch
}

void nlohmann::adl_serializer<SessionManager>::to_json(json &j, const admin_namespace::SessionManager &rh)
{
    j = json{
        {"id", rh.getAdminId()},
        {"currentAdmin", *rh.currentAdmin()},
        {"created-at", rh.getCreatedAT()},
        {"lasttime-loggedin", rh.getLastLogin()},
        {"status", rh.getStatus()},

    };
}

void nlohmann::adl_serializer<SessionManager>::from_json(const json &j, admin_namespace::SessionManager &rh)
{
    rh.setAdminID(j.at("id").get<int>());
    rh.setCreatedAT(j.at("created-at").get<time_t>());
    rh.setCurrentAdmin(new Admin(j.at("currentAdmin").get<Admin>()));
    rh.setLastLogin(j.at("lasttime-loggedin").get<time_t>());
    rh.setStatus(j.at("status").get<SessionStatus>());
}