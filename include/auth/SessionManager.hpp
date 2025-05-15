#ifndef SESSION_MANAGER_H
#define SESSION_MANAGER_H

// Forward declaration to avoid circular dependency
class Student;
class Admin;
class ShoppingCart;
#include <string>
#include "utils/Utilities.hpp"
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;

class SessionBase
{
public:
    time_t getCreatedAT() const { return _created_at; }
    time_t getLastLogin() const { return _lasttime_login; }
    SessionStatus getStatus() const { return _status; };
    void setLastLogin(time_t now);
    void setStatus(SessionStatus status)
    {
        this->_status = status;
    }
    virtual void login(string, string) = 0;
    virtual void logout() = 0;

protected:
    virtual void load_session() = 0;
    virtual void save_session() = 0;
    time_t _created_at = 0;
    time_t _lasttime_login = 0;
    SessionStatus _status = SessionStatus::ANONYMOUS;
};

namespace StudentSession
{
    class SessionManager : public SessionBase
    {
    public:
        static SessionManager &instance()
        {
            static SessionManager _instance;
            return _instance;
        }
        void login(string, string) override;
        void logout() override;

        Student *currentStudent()
        {
            return this->_currentStudent;
        }

        ShoppingCart *shoppingCart()
        {
            return this->_shopping_cart;
        }

        int getStudentID() const { return _student_id; }

    private:
        void load_session() override;
        void save_session() override;
        Student *_currentStudent;
        ShoppingCart *_shopping_cart;
        int _student_id;
        SessionManager();
        SessionManager(const SessionManager &) = delete;
        SessionManager &operator=(const SessionManager &) = delete;
    };
};

namespace AdminSession
{
    class SessionManager : public SessionBase
    {
    public:
        static SessionManager &instance()
        {
            static SessionManager _instance;
            return _instance;
        }

        void login(string, string) override;
        void logout() override;

        Admin *currentAdmin()
        {
            return this->_current_admin;
        }
        int getAdminId() const
        {
            return this->_admin_id;
        }

    private:
        void load_session() override;
        void save_session() override;
        Admin *_current_admin;
        int _admin_id;
        SessionManager() = default;
        SessionManager(const SessionManager &) = delete;
        SessionManager &operator=(const SessionManager &) = delete;
    };
};

#endif
