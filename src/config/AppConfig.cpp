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