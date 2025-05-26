#include "roles/Student.hpp"
#include <iostream>

using namespace std;

// Parameterized constructor

Student::Student(int id, string studentID, string name, string lastName, string hash, string email, string phone)
    : User(id, name, lastName, hash)
{
    this->setStudentID(studentID);
    this->setEmail(email);
    this->setPhone(phone);
    this->setBalance(0);
    this->activate();
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