#include "auth/SessionManager.hpp"
#include <iostream>
using namespace std;

// this is deleted now , instead we will define a non member function
// void AdminSession::SessionManager::sign_in()
// {
//     string password, repeat_password, name;
//     cout << "Enter your Name: ";
//     cin >> name;
//     cout << "Enter your prefer Password: ";
//     cin >> password;
//     cout << "Re-peat your Password: ";
//     cin >> repeat_password;
//     if (password == repeat_password)
//     {
//     }
//     else
//         throw runtime_error("Pass and it's Re-peat doesn't match! :(");
// }

// void SessionBase::login()
// {
//     cout << "enter your Student_ID: ";
//     string id, password;
//     cin >> id;
//     cout << "enter your password: ";
//     cin >> password;
//     // TODO : search through created files of the system to find it , or in the csv given to program by admin to find this student
//     this->_status = SessionStatus::AUTHENTICATED;
// }

// creating the overrided functions

void SessionBase::setLastLogin(time_t now)
{
    if (_lasttime_login == 0 || _lasttime_login < now)
    {
        this->_lasttime_login = now;
    }
    else
        throw invalid_argument("Wrong value! to set as LastLogin time! :(");
}
