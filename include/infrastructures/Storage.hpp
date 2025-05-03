#ifndef STORAGE_HPP
#define STORAGE_HPP

#include "../foodservice/Meal.hpp"
#include "../foodservice/DiningHall.hpp"
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
    vector<DiningHall> allDiningHalls;

private:
    Storage()
    {
        /*
            initializing the values from files
        */
    } // Private constructor to prevent instantiation
    int _mealIDCounter;
    int _diningHallIDCounter;
};

#endif // STORAGE_HPP