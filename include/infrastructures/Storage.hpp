#ifndef STORAGE_HPP
#define STORAGE_HPP

#include "foodservice/Meal.hpp"
#include "foodservice/DiningHall.hpp"
#include <vector>

// alternative ways :
/*
    putting a getAll method in meals for example as a static method
    or do int this in Panel class
*/

class Storage
{
public:
    static Storage &instance()
    {
        static Storage _instance;
        return _instance;
    }
    vector<Meal> allMeals;
    void addMeal(Meal);
    void addDinningHall(DinningHall);
    void removeMeal(int);
    void removeDinningHall(int);
    void MealActivation(int, bool);
    int getMealLastID() { return _mealIDCounter; }
    int getDinningHallLastID() { return _diningHallIDCounter; }
    vector<Meal>::iterator findMeal(int);
    vector<DinningHall>::iterator findDiningHall(int);
    vector<DinningHall> allDiningHalls;

private:
    Storage();
    int _mealIDCounter;
    int _diningHallIDCounter;
};

#endif // STORAGE_HPP