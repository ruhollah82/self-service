#include "../include/Meal.hpp"
#include "../include/DiningHall.hpp"
#include <iostream>
using namespace std;

// DiningHall -------------------------------------------------

void DiningHall::print()
{
    cout << "Dining Hall Information:" << endl;
    cout << "Hall ID: " << getHallID() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Address: " << getAddress() << endl;
    cout << "Capacity: " << getCapacity() << endl;
}

// ------------------------------------------------------------

// Meal ------------------------------------------------------

// Default constructor
Meal::Meal()
    : _mealID(0), _name(""), _price(0.0), _isActive(false), _mealType(MealType::BREAKFAST), _dinginHall(DiningHall())
{
}

// Parameterized constructor
Meal::Meal(string name, float price, vector<string> sideItems, DiningHall serves_in)
    : _mealID(0), _name(name), _price(price), _isActive(true), _mealType(MealType::BREAKFAST), _sideItems(sideItems), _dinginHall(serves_in)
{
}
void Meal::print()
{
    cout << "Meal Information:" << endl;
    cout << "Meal ID: " << getMealID() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Price: " << getPrice() << endl;
    cout << "Active: " << (isActive() ? "Yes" : "No") << endl;
    cout << "Meal Type: ";
    switch (getMealType())
    {
    case MealType::BREAKFAST:
        cout << "Breakfast";
        break;
    case MealType::DINNER:
        cout << "Dinner";
        break;
    case MealType::LAUNCH:
        cout << "Launch";
        break;
    }
    cout << endl;
    cout << "Side Items: ";
    for (const auto &item : getSideItems())
    {
        cout << item << " ";
    }
    cout << endl;
}
// -----------------------------------------------------------