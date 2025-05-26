#include "infrastructures/FileSystem.hpp"
#include "config/ConfigPaths.hpp"
#include "auth/SessionManager.hpp"
#include "infrastructures/Storage.hpp"
#include "foodservice/Filling.hpp"
#include "interface/Panel.hpp"
#include "utils/Utilities.hpp"
#include <iostream>
#include <filesystem>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;
namespace fs = std::filesystem;
void initialization();
void createDirs();
void admin_sign_in();
bool loginIntractive();

int main()
{
    initialization();
    bool is_student = loginIntractive();
    if (is_student)
    {
        student_namespace::Panel panel;
        int action = 0;
        while (true)
        {
            panel.showMenu();
            cin >> action;
            panel.Action(action);
        }
    }
    else
    {
        admin_namespace::Panel panel;
        int action = 0;
        while (true)
        {
            panel.showMenu();
            cin >> action;
            panel.action(action);
        }
    }

    return 0;
}

void initialization()
{
    createDirs();
    if (!admin_namespace::SessionManager::isThereAnyAdmin())
    {
        cout << "Seems this is the first time that program is running so WELLCOME :)";
        cout << endl
             << "Please Enter your info as System Admin: ";
        admin_sign_in();
    }
}

void createDirs()
{
    for (auto path : config::ConfigPaths::instance().allDirs())
    {
        if (!FileSystem::ifNotExistsCreate(path))
        {
            cerr << "Seems we can't continue :(";
            exit(0);
        }
    }
}

void admin_sign_in()
{
    string name, lastname, password, repPassword;
    cout << "Enter Your name: ";
    getline(cin, name);
    cout << "Enter Your Last Name: ";
    getline(cin, lastname);
    cout << "Enter Your prefer Password: ";
    getline(cin, password);
    cout << "Repeat Your Password: ";
    getline(cin, repPassword);
    if (password == repPassword)
    {
        admin_namespace::SessionManager::sign_in(name, lastname, password);
        cout << "Hooray The SINGIN process was Successful :)";
    }
    else
    {
        cerr << "Password and it's Repeatation didn't match so GOOD BYE :)";
        exit(0);
    }
}

bool loginIntractive()
{
    string username, password;
    cout << "Enter your username: ";
    getline(cin, username);
    cout << "Enter your Password: ";
    getline(cin, password);
    bool is_student = all_of(username.begin(), username.end(), [](char c)
                             { return isdigit(c); });
    if (is_student)
    {
        student_namespace::SessionManager::instance().login(username, password);
    }
    else
    {
        admin_namespace::SessionManager::instance().login(username, password);
    }
    return is_student;
}