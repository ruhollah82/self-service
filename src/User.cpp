#include "../include/User.hpp"
#include "iostream"

// User -------------------------------------------------------
int User::_staticUserID = 0;

User::User() : _userID(++_staticUserID), _name(""), _lastName(""), _hashedPassword("") {}

User::User(string name, string lastName, string hashedPassword) : _name(name), _lastName(lastName), _hashedPassword(hashedPassword) {}

void User::print() const
{
    cout << "ID: " << _userID << ", Name: " << _name << " " << _lastName << endl;
}
