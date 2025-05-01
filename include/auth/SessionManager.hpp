#pragma once
#include "roles/Student.hpp"
class SessionManager
{
public:
    static SessionManager &instace()
    {
        static SessionManager instace;
        return instace;
    }

    Student &currentStudent()
    {
        return *_currentStudent;
    }

private:
    Student *_currentStudent;
    SessionManager()
    {
        _currentStudent = new Student("4011226319", "Alireza", "Sharifi", "123456789");
    }
    SessionManager(const SessionManager &) = delete;
    SessionManager &operator=(const SessionManager &) = delete;
};