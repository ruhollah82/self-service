#include "auth/SessionManager.hpp"
#include "roles/Student.hpp"
#include "payment/ShoppingCart.hpp"
#include "auth/Filling.hpp"
#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>
using namespace std;
using namespace student_namespace;
using json = nlohmann ::json;

student_namespace::SessionManager::SessionManager() : _student_id(-1)
{
    this->setStatus(SessionStatus::ANONYMOUS);
}

// Implementation of overrided fucntions
bool student_namespace::SessionManager::login(string student_id, string password)
{
    if (filling::Auth<SessionManager>::sessionExists(student_id))
    {
        load_session(student_id);
        if (this->currentStudent()->checkPassword(password))
        {
            this->setLastLogin(time(0));
            this->setStatus(SessionStatus::AUTHENTICATED);
            return true;
        }
        else
        {
            this->logout();
            cerr << "Wrong Password :(";
            return false;
        }
    }
    Student temp;
    try
    {
        temp = filling::Auth<SessionManager>::giveStudentfromCSV(student_id);
        if (temp.checkPassword(password))
        {
            this->_currentStudent = &temp;
            this->setStudentID(temp.getID());
            this->setShoppingCart(new ShoppingCart());
            this->setLastLogin(time(0));
            return true;
        }
    }
    catch (exception &e)
    {
        cerr << e.what() << endl;
        return false;
    }
    return false;
}

void student_namespace::SessionManager::logout()
{
    save_session();
    delete this->_currentStudent;
    delete this->_shopping_cart;
    this->_currentStudent = nullptr;
    this->_shopping_cart = nullptr;
    this->_student_id = -1;
    this->_status = SessionStatus::ANONYMOUS;
}

void student_namespace::SessionManager::load_session(string student_id)
{
    auto file = filling::Auth<SessionManager>::sessionFile(student_id);
    if (file != "")
    {
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
void student_namespace::SessionManager::save_session()
{
    auto file = filling::Auth<SessionManager>::sessionFile(this->currentStudent()->getStudentID());
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

void nlohmann::adl_serializer<student_namespace::SessionManager>::to_json(
    nlohmann::json &j, const student_namespace::SessionManager &rh)
{
    j = json{
        {"student-id", rh.getStudentID()},
        {"created-at", rh.getCreatedAT()},
        {"lasttime-loggedin", rh.getLastLogin()},
        {"status", rh.getStatus()},
        {"shoppingcart", *rh.shoppingCart()},
    };
}

void nlohmann::adl_serializer<student_namespace::SessionManager>::from_json(
    const nlohmann::json &j, student_namespace::SessionManager &rh)
{
    rh.setStudentID(j.at("student-id").get<int>());
    rh.setCreatedAT(j.at("created-at").get<time_t>());
    rh.setLastLogin(j.at("lasttime-loggedin").get<time_t>());
    rh.setStatus(j.at("status").get<SessionStatus>());
    ShoppingCart *sh = new ShoppingCart(j.at("shoppingcart").get<ShoppingCart>());
    rh.setShoppingCart(sh);
}
