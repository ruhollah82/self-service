#include "foodservice/DiningHall.hpp"
#include <nlohmann/json.hpp>
#include <iostream>
using namespace std;
using json = nlohmann::json;
// Default constructor
DinningHall::DinningHall()
    : _hallID(0), _name(""), _address(""), _capacity(0)
{
}

// Parameterized constructor
DinningHall::DinningHall(int hallID, string name, string address, int capacity)
    : _hallID(hallID), _name(name), _address(address), _capacity(capacity)
{
}

void DinningHall::print()
{
    cout << "Dining Hall Information:" << endl;
    cout << "Hall ID: " << getHallID() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Address: " << getAddress() << endl;
    cout << "Capacity: " << getCapacity() << endl;
}
void DinningHall::input()
{
    cout << "enter the name: ";
    string name, address;
    cin >> name;
    cout << "enter the address: ";
    cin >> address;
    int cap;
    cout << "enter the capacity: ";
    cin >> cap;

    this->setName(name);
    this->setAddress(address);
    this->setCapacity(cap);
}