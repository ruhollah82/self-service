#ifndef SESSION_MANAGER_H
#define SESSION_MANAGER_H

// Forward declaration to avoid circular dependency
#include <string>
#include "utils/Utilities.hpp"
#include <filesystem>
#include <nlohmann/json.hpp>
class Student;
class Admin;
class ShoppingCart;
namespace fs = std::filesystem;
using namespace std;
using json = nlohmann::json;

class SessionBase
{
public:
    time_t getCreatedAT() const { return _created_at; }
    time_t getLastLogin() const { return _lasttime_login; }
    SessionStatus getStatus() const { return _status; }
    void setLastLogin(time_t now);
    void setStatus(SessionStatus status)
    {
        this->_status = status;
    }
    virtual bool login(string, string) = 0;
    virtual void logout() = 0;
    void setCreatedAT(time_t t) { this->_created_at = t; }

protected:
    SessionBase()
    {
        this->_created_at = time(0);
    }
    virtual void load_session(string) = 0;
    virtual void save_session() = 0;
    time_t _created_at = 0;
    time_t _lasttime_login = 0;
    SessionStatus _status = SessionStatus::ANONYMOUS;
};

namespace student_namespace
{
    class SessionManager : public SessionBase
    {
    public:
        static SessionManager &instance()
        {
            static SessionManager _instance;
            return _instance;
        }
        bool login(string, string) override;
        void logout() override;

        Student *currentStudent() const
        {
            return this->_currentStudent;
        }

        ShoppingCart *shoppingCart() const
        {
            return this->_shopping_cart;
        }
        void setShoppingCart(ShoppingCart *sh)
        {
            this->_shopping_cart = sh;
        }
        void setCurrentStudent(Student *st)
        {
            this->_currentStudent = st;
        }

        int getStudentID() const { return _student_id; }
        void setStudentID(int id)
        {
            this->_student_id = id;
        }

    private:
        void load_session(string) override;
        void save_session() override;
        Student *_currentStudent;
        ShoppingCart *_shopping_cart;
        int _student_id;
        SessionManager();
        SessionManager(const SessionManager &) = delete;
        SessionManager &operator=(const SessionManager &) = delete;
    };
};

namespace admin_namespace
{
    class SessionManager : public SessionBase
    {
    public:
        static SessionManager &instance()
        {
            static SessionManager _instance;
            return _instance;
        }

        static bool sign_in(string, string, string);
        static bool isThereAnyAdmin();

        bool login(string, string) override;
        void logout() override;

        Admin *currentAdmin() const
        {
            return this->_current_admin;
        }
        void setCurrentAdmin(Admin *ad)
        {
            this->_current_admin = ad;
        }
        int getAdminId() const
        {
            return this->_admin_id;
        }
        void setAdminID(int id)
        {
            this->_admin_id = id;
        }

    private:
        void load_session(string) override;
        void save_session() override;
        Admin *_current_admin;
        int _admin_id;
        SessionManager() = default;
        SessionManager(const SessionManager &) = delete;
        SessionManager &operator=(const SessionManager &) = delete;
    };
};

namespace nlohmann
{
    template <>
    struct adl_serializer<student_namespace::SessionManager>
    {
        static void to_json(json &, const student_namespace::SessionManager &);
        static void from_json(const json &, student_namespace::SessionManager &);
    };

    template <>
    struct adl_serializer<admin_namespace::SessionManager>
    {
        static void to_json(json &, const admin_namespace::SessionManager &);
        static void from_json(const json &, admin_namespace::SessionManager &);
    };
}
#endif
