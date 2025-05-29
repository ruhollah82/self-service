#include "foodservice/Meal.hpp"
#include <nlohmann/json.hpp>
#include <iostream>
#include "foodservice/Meal.hpp"
#include "infrastructures/Storage.hpp"
#include "interface/Panel.hpp"
#include "utils/StringUtils.hpp"
using namespace std;
using json = nlohmann::json;

// Default constructor
Meal::Meal()
    : _mealID(0), _name(""), _price(0.0), _isActive(false), _mealType(MealType::BREAKFAST)
{
}

// Parameterized constructor
Meal::Meal(int id, string name, float price, vector<string> sideItems)
    : _mealID(id), _reserveDay(ReserveDay::SAT), _name(name), _price(price), _isActive(true), _mealType(MealType::BREAKFAST), _sideItems(sideItems)
{
}
void Meal::print()
{
    cout << "Meal " << this->getMealID() << " Information:" << endl;
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
    if (getSideItems().size())
        for (const auto &item : getSideItems())
        {
            cout << item << " ";
        }
    else
        cout << "Nothing";
    cout << endl;
}

void Meal::addSideItem(string side_item)
{
    this->_sideItems.push_back(side_item);
}

void Meal::addPrice(float value)
{
    if (value >= 0)
    {
        this->setPrice(this->getPrice() + value);
    }
    else
        throw invalid_argument("Value is too LOW! :(");
}
void Meal::input()
{
    string name;
    int id;
    float price;
    cout << "enter the name: ";
    getline(cin, name);
    cout << "enter the price: ";
    cin >> price;
    MealType type = panel_utils::_chooseMealType();
    ReserveDay day = panel_utils::_chooseDay();
    this->setName(name);
    this->setPrice(price);
    this->setMealType(type);
    this->setResesrveDay(day);
    this->activate();
    cout << "enter the side items seperated by '-': ";
    string side_item;
    cin.ignore();
    getline(cin, side_item);
    if (side_item[side_item.size() - 1] != '-')
    {
        side_item += '-';
    }
    stringstream ss = stringstream(side_item);
    this->_sideItems.clear();
    while (getline(ss, side_item, '-'))
    {
        if (side_item.size())
            this->addSideItem(string_utils::strip(side_item, ' '));
    }
    cout << "Meal Created Successfuly :)" << endl;
}

// -----------------------------------------------------------