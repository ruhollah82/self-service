#pragma once
#include <filesystem>
#include "auth/SessionManager.hpp"
namespace fs = std::filesystem;
class AppConfig
{
public:
    static AppConfig &instance()
    {
        static AppConfig _instance;
        return _instance;
    }
    fs::path d_users = "users";
    fs::path d_config = "config";
    fs::path d_students = d_users / "students";
    fs::path d_admins = d_users / "admins";
    fs::path d_currentStudent()
    {
        if (SessionManager::instace().getStatus() == SessionStatus::AUTHENTICATED)
        {
            return (d_students / SessionManager::instace().currentStudent().getStudentID());
        }
        else
            throw runtime_error("Student is not Authenticated to obtain it's Dir! :(");
    }
    fs::path d_student(Student *st)
    {
        return d_students / st->getStudentID();
    }
    fs::path d_student_reservations()
    {
        return d_currentStudent() / "reservations";
    }
    fs::path j_student_info(Student *st = nullptr)
    {
        if (!st)
            return d_currentStudent() / "info.json";
        else
            return d_student(st) / "info.json";
    }

private:
    AppConfig() = default;
    AppConfig(const AppConfig &) = delete;
    void operator=(const AppConfig &) = delete;
};