#include "config/ConfigPaths.hpp"
#include "roles/Student.hpp"

fs::path config::ConfigPaths::d_student(Student *st)
{
    if (!st)
    {
        if (student_namespace::SessionManager::instance().getStatus() == SessionStatus::AUTHENTICATED)
        {
            return (d_students / student_namespace::SessionManager::instance().currentStudent()->getStudentID());
        }
        else
            throw runtime_error("Student is not Authenticated to obtain it's Dir! :(");
    }
    else
    {
        return d_students / st->getStudentID();
    }
}

fs::path config::ConfigPaths::j_reservations(Student *st)
{
    if (!st)
    {
        if (student_namespace::SessionManager::instance().getStatus() == SessionStatus::AUTHENTICATED)
        {
            return (d_student() / "reservations.json");
        }
        else
            throw runtime_error("Student is not Authenticated to obtain it's Dir! :(");
    }
    else
    {
        return this->d_student(st) / "reservations.json";
    }
}

// fs::path config::ConfigPaths::j_student_info(Student *st)
// {
//     if (!st)
//         return d_student() / "info.json";
//     else
//         return d_student(st) / "info.json";
// }

vector<fs::path> &config::ConfigPaths::allDirs()
{
    return *(new vector<fs::path>({
        this->d_admin_sessions,
        this->d_student_sessions,
        this->d_students,
        this->d_foodservice,
        this->d_config,
    }));
}