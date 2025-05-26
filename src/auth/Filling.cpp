#include "auth/Filling.hpp"
#include "auth/SessionManager.hpp"
#include "config/ConfigPaths.hpp"
#include "roles/Student.hpp"
#include "utils/StringUtils.hpp"
#include "infrastructures/FileSystem.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
using namespace filling;
template <>
bool filling::Auth<student_namespace::SessionManager>::sessionExists(string student_id)
{
    return FileSystem::exists(sessionFile(student_id));
}
template <>
bool filling::Auth<admin_namespace::SessionManager>::sessionExists(string name)
{
    return FileSystem::exists(sessionFile(name));
}

template <>
fs::path filling::Auth<student_namespace::SessionManager>::sessionFile(string student_id)
{
    return config::ConfigPaths::instance().d_student_sessions / (student_id + ".json");
}
template <>
fs::path filling::Auth<admin_namespace::SessionManager>::sessionFile(string name)
{
    return config::ConfigPaths::instance().d_admin_sessions / (name + ".json");
}
