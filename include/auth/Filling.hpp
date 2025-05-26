#pragma once
#include <string>
#include <filesystem>
#include "auth/SessionManager.hpp"
#include "infrastructures/FileSystem.hpp"
#include "roles/Student.hpp"
#include <string>
#include <fstream>
#include <vector>
#include "utils/StringUtils.hpp"
using namespace std;
namespace fs = std::filesystem;
namespace filling
{
    template <typename T>
    class Auth
    {
    public:
        static bool sessionExists(string);
        static fs::path sessionFile(string);
        static Student giveStudentfromCSV(string);
    };
    template <typename T>
    Student Auth<T>::giveStudentfromCSV(string student_ID)
    {
        auto file = config::ConfigPaths::instance().c_students;
        ifstream readerCsv(file);
        string s, temp;
        while (true)
        {
            getline(readerCsv, s, '\n');
            stringstream ss(s.substr(0, s.size() - 1) + ',');
            vector<string> vals;
            while (getline(ss, temp, ','))
            {
                vals.push_back(string_utils::strip(temp, ' '));
            }
            if (vals[1] == student_ID)
            {
                try
                {

                    return Student(stoi(vals[0]), vals[1], vals[2], vals[3], vals[4], vals[5], vals[6]);
                }
                catch (...)
                {
                    throw runtime_error("error happends when returning the student obj :(");
                }
            }
            else
            {
                vals.clear();
            }
        }
    }

    template <>
    bool Auth<student_namespace::SessionManager>::sessionExists(string);
    template <>
    bool Auth<admin_namespace::SessionManager>::sessionExists(string);
    template <>
    fs::path Auth<student_namespace::SessionManager>::sessionFile(string);
    template <>
    fs::path Auth<admin_namespace::SessionManager>::sessionFile(string);
}
