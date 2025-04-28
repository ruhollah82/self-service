#ifndef STORAGE_HPP
#define STORAGE_HPP

#include "Meal.hpp"
#include "DiningHall.hpp"
#include <vector>

// alternative ways :
/*
    putting a getAll method in meals for example as a static method
    or do int this in Panel class
*/

class Storage
{
public:
    static vector<Meal> allMeals;
    static vector<DiningHall> allDiningHalls;

    static void initialize(); // Optional: To populate the vectors
};

#endif // STORAGE_HPP