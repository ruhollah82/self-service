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

void admin_namespace::SessionManager::login(string name, string password)
{
    if (filling::Auth<SessionManager>::sessionExists(name))
    {
        load_session(name);
        if (this->currentAdmin()->checkPassword(password))
        {
            this->setLastLogin(time(0));
            this->setStatus(SessionStatus::AUTHENTICATED);
        }
        else
        {
            this->logout();
            cerr << "Wrong Answer :(";
        }
    }
    else
    {
        cerr << "There isn't any Admin Session with specified name :(";
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
    temp->setHashedPassword(password);
    instance().setCurrentAdmin(temp);
    instance().setAdminID(temp->getID());
    instance().setCreatedAT(time(0));
    instance().setStatus(SessionStatus::AUTHENTICATED);
    instance().save_session();
    instance().logout();
    return true; // using try catch
}