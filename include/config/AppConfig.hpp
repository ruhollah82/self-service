#pragma once
#include <filesystem>
#include "auth/SessionManager.hpp"
namespace fs = std::filesystem;
namespace config
{

    class AppConfig
    {
    public:
        static AppConfig &instance()
        {
            static AppConfig _instance;
            return _instance;
        }

        // JSON files Pathes and Directories:
        fs::path d_users = "users";
        fs::path d_config = "config";
        fs::path j_users_config = d_config / "user-config.json";
        fs::path j_AppConfig = d_config / "app-config.json";
        fs::path d_foodservice = "foodservice";
        fs::path j_meals = d_foodservice / "meals.json";
        fs::path j_dining_halls = d_foodservice / "dininghalls.json";
        fs::path d_students = d_users / "students";
        fs::path d_admins = d_users / "admins";
        fs::path d_student(Student * = nullptr);
        fs::path j_student_info(Student * = nullptr);
        fs::path j_reservations(Student * = nullptr);
        fs::path d_sessions = "sessions";
        fs::path j_session_lookup = "session-lookup.json";

        unsigned int session_lifetime_min = 60;

    private:
        AppConfig() = default;
        AppConfig(const AppConfig &) = delete;
        void operator=(const AppConfig &) = delete;
    };
}