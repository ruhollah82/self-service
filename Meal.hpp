#ifndef MEAL_HPP
#define MEAL_HPP

#include <string>
#include <vector>
#include "DiningHall.hpp"

using namespace std;

class Meal
{
private:
    int meal_id;
    string name;
    float price;
    string date;
    string meal_type;
    vector<string> side_items;
    DiningHall *dining_hall;

public:
};

#endif // MEAL_HPP
