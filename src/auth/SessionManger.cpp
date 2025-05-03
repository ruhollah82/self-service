#include "auth/SessionManager.hpp"
#include "roles/Student.hpp"
#include <iostream>

using namespace std;

SessionManager::SessionManager() : _currentStudent(new Student("4011226319", "alireza", "sharifi", "123456"))
{
}
void SessionManager::login()
{
    cout << "enter your Student_ID: ";
    string student_id, password;
    cin >> student_id;
    cout << "enter your password: ";
    cin >> password;
    // TODO : search through created files of the system to find it , or in the csv given to program by admin to find this student
    this->_status = SessionStatus::AUTHENTICATED;
}

void SessionManager::logout()
{
    this->_currentStudent = nullptr;
    this->_student_id = 0;
    this->_status = SessionStatus::ANONYMOUS;
}

void SessionManager::setLastLogin(time_t now)
{
    if (_lasttime_login == 0 || _lasttime_login < now)
    {
        this->_lasttime_login = now;
    }
    else
        throw invalid_argument("Wrong value! to set as LastLogin time! :(");
}