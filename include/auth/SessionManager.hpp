
#ifndef SESSION_MANAGER_H
#define SESSION_MANAGER_H

// Forward declaration to avoid circular dependency
class Student;

#include "utils/Utilities.hpp"
#include <filesystem>
#include <unordered_map>
namespace fs = std::filesystem;

class SessionManager
{
public:
    static SessionManager &instance()
    {
        static SessionManager instace;
        return instace;
    }

    Student *currentStudent()
    {
        return this->_currentStudent;
    }

    void login();
    void logout();

    void load_session();
    void save_session();

    int getStudentID() const { return _student_id; }
    time_t getCreatedAT() const { return _created_at; }
    time_t getLastLogin() const { return _lasttime_login; }
    SessionStatus getStatus() const { return _status; };
    void setLastLogin(time_t now);
    void setStatus(SessionStatus status)
    {
        this->_status = status;
    }

private:
    Student *_currentStudent;
    int _student_id;
    time_t _created_at = 0;
    time_t _lasttime_login = 0;
    SessionStatus _status = SessionStatus::ANONYMOUS;
    SessionManager();
    SessionManager(const SessionManager &) = delete;
    SessionManager &operator=(const SessionManager &) = delete;
};
#endif
