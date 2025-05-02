#pragma once
#include "roles/Student.hpp"
#include "utils/Utilities.hpp"
#include <filesystem>
namespace fs = std::filesystem;

class SessionManager
{
public:
    static SessionManager &instace()
    {
        static SessionManager instace;
        return instace;
    }

    Student &currentStudent() const
    {
        return *_currentStudent;
    }

    void login();
    void logout();

    void load_session();
    void save_session();

    int getStudentID() const { return _student_id; }
    time_t getCreatedAT() const { return _created_at; }
    time_t getLastLogin() const { return _lasttime_login; }
    SessionStatus getStatus() const { return _status; };
    void setLastLogin(time_t now)
    {
        if (_lasttime_login == 0 || _lasttime_login < now)
        {
            this->_lasttime_login = now;
        }
        else
            throw invalid_argument("Wrong value! to set as LastLogin time! :(");
    }
    void setStatus(SessionStatus status)
    {
        this->_status = status;
    }

private:
    Student *_currentStudent;
    int _student_id;
    time_t _created_at = 0;
    time_t _lasttime_login = 0;
    int _expire_lifetime_min = 60;
    SessionStatus _status = SessionStatus::ANONYMOUS;
    SessionManager()
    {
        _currentStudent = new Student("4011226319", "Alireza", "Sharifi", "123456789");
    }
    SessionManager(const SessionManager &) = delete;
    SessionManager &operator=(const SessionManager &) = delete;
};
