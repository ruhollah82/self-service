#ifndef MEAL_HPP
#define MEAL_HPP
#include "DiningHall.hpp"
#include "Utilities.hpp"
#include <vector>
using namespace std;

class Meal
{
public:
    Meal();
    Meal(string name, float price, vector<string> sideItems);
    ReserveDay getReserveDay() const { return _reserveDay; }
    // Getters
    int getMealID() const { return _mealID; }
    string getName() const { return _name; }
    float getPrice() const { return _price; }
    bool isActive() const { return _isActive; }
    MealType getMealType() const { return _mealType; }
    vector<string> getSideItems() const { return _sideItems; }

    // Setters
    // void setMealID(int mealID) { _mealID = mealID; }
    void setName(string name) { _name = name; }
    void setPrice(float price) { _price = price; }
    void setMealType(MealType mealType) { _mealType = mealType; }
    void setSideItems(vector<string> sideItems) { _sideItems = sideItems; }
    void setResesrveDay(ReserveDay reserveDay) { _reserveDay = reserveDay; }

    // Activation and DeActivation
    void activate() { _isActive = true; }
    void deactivate() { _isActive = false; }

    // Other Methods
    void print();
    void addSideItem(string);
    void addPrice(float);

private:
    int _mealID;
    string _name;
    float _price;
    bool _isActive;
    MealType _mealType;
    ReserveDay _reserveDay;
    vector<string> _sideItems;
};

#endif