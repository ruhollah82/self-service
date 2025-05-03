#include "config/AppConfig.hpp"
#include "roles/Student.hpp"

fs::path AppConfig::d_student(Student *st)
{
    if (!st)
    {
        if (SessionManager::instance().getStatus() == SessionStatus::AUTHENTICATED)
        {
            return (d_students / SessionManager::instance().currentStudent()->getStudentID());
        }
        else
            throw runtime_error("Student is not Authenticated to obtain it's Dir! :(");
    }
    else
    {
        return d_students / st->getStudentID();
    }
}

fs::path AppConfig::j_reservations(Student *st)
{
    if (!st)
    {
        if (SessionManager::instance().getStatus() == SessionStatus::AUTHENTICATED)
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

fs::path AppConfig::j_student_info(Student *st)

{
    if (!st)
        return d_student() / "info.json";
    else
        return d_student(st) / "info.json";
}