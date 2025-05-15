#include "auth/SessionManager.hpp"
#include "roles/Student.hpp"
#include <iostream>
using namespace std;

StudentSession::SessionManager::SessionManager() : _currentStudent(new Student("4011226319", "alireza", "sharifi", "123456"))
{
}

// Implementation of overrided fucntions
void StudentSession::SessionManager::login(string, string)
{
}

void StudentSession::SessionManager::logout()
{
    // this->_currentStudent = nullptr;
    // this->_student_id = 0;
    this->_status = SessionStatus::ANONYMOUS;
}

void StudentSession::SessionManager::load_session()
{
}
void StudentSession::SessionManager::save_session()
{
}