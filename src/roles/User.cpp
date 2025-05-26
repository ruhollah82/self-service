#include "roles/User.hpp"
#include <bcrypt/BCrypt.hpp>
#include "iostream"

// User -------------------------------------------------------

User::User() : _userID(0), _name(""), _lastName(""), _hashedPassword("") {}

User::User(int id, string name, string lastName, string hashedPassword) : _userID(id), _name(name), _lastName(lastName), _hashedPassword(hashedPassword) {}

void User::print() const
{
    cout << "ID: " << _userID << ", Name: " << _name << " " << _lastName << endl;
}

bool User::checkPassword(string password)
{
    return BCrypt::validatePassword(password, this->_hashedPassword);
}

void User::setPassword(string password)
{
    this->_hashedPassword = BCrypt::generateHash(password);
}

void User::setHashedPassword(string hash_password)
{
    this->_hashedPassword = hash_password;
}
