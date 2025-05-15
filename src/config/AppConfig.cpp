#include "config/AppConfig.hpp"
#include "roles/Student.hpp"

fs::path config::AppConfig::d_student(Student *st)
{
    if (!st)
    {
        if (StudentSession::SessionManager::instance().getStatus() == SessionStatus::AUTHENTICATED)
        {
            return (d_students / StudentSession::SessionManager::instance().currentStudent()->getStudentID());
        }
        else
            throw runtime_error("Student is not Authenticated to obtain it's Dir! :(");
    }
    else
    {
        return d_students / st->getStudentID();
    }
}

fs::path config::AppConfig::j_reservations(Student *st)
{
    if (!st)
    {
        if (StudentSession::SessionManager::instance().getStatus() == SessionStatus::AUTHENTICATED)
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

fs::path config::AppConfig::j_student_info(Student *st)
{
    if (!st)
        return d_student() / "info.json";
    else
        return d_student(st) / "info.json";
}