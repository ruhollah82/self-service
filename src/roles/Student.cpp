#include "roles/Student.hpp"
#include <bcrypt/BCrypt.hpp>
#include <iostream>

using namespace std;

// Default constructor
// Student::Student() : User() {}

// Parameterized constructor

Student::Student(string studentID, string name, string lastName, string password)
{
    this->setStudentID(studentID);
    this->setName(name);
    this->setLastName(lastName);
    this->setHashedPassword(password);
}

bool Student::checkPassword(string password)
{
    return BCrypt::validatePassword(password, this->_hashedPassword);
}

void Student::setHashedPassword(string password)
{
    this->_hashedPassword = BCrypt::generateHash(password);
}

// Student-specific methods
void Student::reserveMeal()
{
    cout << "Reserving a meal..." << endl;
}

void Student::cancelReservation()
{
    cout << "Cancelling a reservation..." << endl;
}

void Student::print() const
{
    cout << "Student Information:" << endl;
    // cout << "User ID: " << getUserID() << endl;
    cout << "Student ID: " << getStudentID() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Last Name: " << getLastName() << endl;
    // cout << "Email: " << getEmail() << endl;
    // cout << "Phone: " << getPhone() << endl;
    // cout << "Balance: " << getBalance() << endl;
    // cout << "Active: " << (isActive() ? "Yes" : "No") << endl;
}