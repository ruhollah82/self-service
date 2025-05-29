#pragma once
#include <filesystem>
#include "auth/SessionManager.hpp"
#include <vector>
namespace fs = std::filesystem;
class Student;
namespace config
{

    class ConfigPaths
    {
    public:
        static ConfigPaths &instance()
        {
            static ConfigPaths _instance;
            return _instance;
        }

        // JSON files Pathes and Directories:
        fs::path exe_dir = "./bin";
        fs::path d_users = exe_dir / "users";
        fs::path d_config = exe_dir / "config";
        fs::path c_students = exe_dir / "students.csv";
        fs::path d_foodservice = exe_dir / "foodservice";
        fs::path d_sessions = exe_dir / "sessions";
        fs::path j_admin_config = d_config / "admin_config.json";
        fs::path j_ConfigPaths = d_config / "config-paths.json";
        fs::path j_meals = d_foodservice / "meals.json";
        fs::path j_dining_halls = d_foodservice / "dininghalls.json";
        fs::path d_students = d_users / "students";
        // fs::path d_admins = d_users / "admins";
        fs::path d_student(Student * = nullptr);
        // fs::path j_student_info(Student * = nullptr);
        fs::path j_reservations(Student * = nullptr);
        fs::path d_student_sessions = d_sessions / "students";
        fs::path d_admin_sessions = d_sessions / "admins";
        fs::path j_foodservice_ids = d_foodservice / "IDs.json";

        // unsigned int session_lifetime_min = 60;
        vector<fs::path> &allDirs();

    private:
        ConfigPaths() = default;
        ConfigPaths(const ConfigPaths &) = delete;
        void operator=(const ConfigPaths &) = delete;
    };
}