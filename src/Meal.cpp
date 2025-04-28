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
    : _mealID(0), _name(""), _price(0.0), _isActive(false), _mealType(MealType::BREAKFAST)
{
}

// Parameterized constructor
Meal::Meal(string name, float price, vector<string> sideItems)
    : _mealID(0), _name(name), _price(price), _isActive(true), _mealType(MealType::BREAKFAST), _sideItems(sideItems)
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
    case MealType::LUNCH:
        cout << "Lunch";
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