#include "foodservice/DiningHall.hpp"
#include <iostream>
using namespace std;
// Default constructor
DiningHall::DiningHall()
    : _hallID(0), _name(""), _address(""), _capacity(0)
{
}

// Parameterized constructor
DiningHall::DiningHall(int hallID, string name, string address, int capacity)
    : _hallID(hallID), _name(name), _address(address), _capacity(capacity)
{
}

void DiningHall::print()
{
    cout << "Dining Hall Information:" << endl;
    cout << "Hall ID: " << getHallID() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Address: " << getAddress() << endl;
    cout << "Capacity: " << getCapacity() << endl;
}
