#include "../include/Admin.hpp"
#include <iostream>

using namespace std;

// Default constructor
Admin::Admin() : User() {}

// Parameterized constructor
Admin::Admin(string adminID, string name, string lastName, string password)
    : User(name, lastName, password) {}

// Admin-specific methods
void Admin::manageUsers()
{
    cout << "Managing users..." << endl;
}

void Admin::manageReservations()
{
    cout << "Managing reservations..." << endl;
}

void Admin::manageMeals()
{
    cout << "Managing meals..." << endl;
}

// Override print method
void Admin::print() const
{
    cout << "Admin - ";
    User::print();
}