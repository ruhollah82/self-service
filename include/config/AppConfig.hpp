#pragma once
#include <filesystem>
#include "auth/SessionManager.hpp"
namespace fs = std::filesystem;
class Student;
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
    fs::path d_foodservice = "foodservice";
    fs::path d_meals = d_foodservice / "meals";
    fs::path d_dining_hall = d_foodservice / "dininghalls";
    fs::path d_students = d_users / "students";
    fs::path d_admins = d_users / "admins";
    fs::path d_student(Student * = nullptr);

    fs::path j_student_info(Student *st = nullptr)
    {
        if (!st)
            return d_student() / "info.json";
        else
            return d_student(st) / "info.json";
    }

    unsigned int session_lifetime_min = 60;

private:
    AppConfig() = default;
    AppConfig(const AppConfig &) = delete;
    void operator=(const AppConfig &) = delete;
};