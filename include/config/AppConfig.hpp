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
    fs::path j_meals = d_foodservice / "meals.json";
    fs::path j_dining_halls = d_foodservice / "dininghalls.json";
    fs::path d_students = d_users / "students";
    fs::path d_admins = d_users / "admins";
    fs::path d_student(Student * = nullptr);

    fs::path j_student_info(Student * = nullptr);
    fs::path j_reservations(Student * = nullptr);
    unsigned int session_lifetime_min = 60;
    fs::path d_sessions = "sessions";
    fs::path j_session_lookup = "session-lookup.json";

private:
    AppConfig() = default;
    AppConfig(const AppConfig &) = delete;
    void operator=(const AppConfig &) = delete;
};