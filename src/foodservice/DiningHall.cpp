#include "foodservice/DiningHall.hpp"
#include <nlohmann/json.hpp>
#include <iostream>
using namespace std;
using json = nlohmann::json;
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

namespace nlohmann
{

    template <>
    struct adl_serializer<DiningHall>
    {

        static void to_json(json &j, DiningHall &diningHall)
        {
            j = json{
                {"HallID", diningHall.getHallID()},
                {"Name", diningHall.getName()},
                {"Address", diningHall.getAddress()},
                {"Capacity", diningHall.getCapacity()},
            };
        }

        static void from_json(json &j, DiningHall &diningHall)
        {
            diningHall.setHallID(j.at("HallID").get<int>());
            diningHall.setName(j.at("Name").get<string>());
            diningHall.setAddress(j.at("Address").get<string>());
            diningHall.setCapacity(j.at("Capacity").get<int>());
        }
    };
};