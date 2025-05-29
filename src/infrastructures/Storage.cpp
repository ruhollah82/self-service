#include "infrastructures/Storage.hpp"
#include "nlohmann/json.hpp"
#include "foodservice/Meal.hpp"
#include "foodservice/DiningHall.hpp"
#include "foodservice/Filling.hpp"

Storage::Storage()
{
    // initialization from files
    allMeals = filling::FoodService<Meal>::giveAll();
    allDiningHalls = filling::FoodService<DinningHall>::giveAll();
    this->_mealIDCounter = filling::FoodService<Meal>::getLastID();
    this->_diningHallIDCounter = filling::FoodService<DinningHall>::getLastID();
}
void Storage::addMeal(Meal meal)
{
    meal.setMealID(++this->_mealIDCounter);
    this->allMeals.push_back(meal);
}

void Storage::addDinningHall(DinningHall d)
{
    d.setHallID(++this->_diningHallIDCounter);
    this->allDiningHalls.push_back(d);
}

vector<Meal>::iterator Storage::findMeal(int id)
{
    vector<Meal>::iterator i = allMeals.begin();
    for (; i != allMeals.end() && i->getMealID() != id; i++)
        ;
    return i;
}
vector<DinningHall>::iterator Storage::findDiningHall(int id)
{
    for (auto i = allDiningHalls.begin(); i != allDiningHalls.end(); i++)
    {
        if (i->getHallID() == id)
        {
            return i;
        }
    }
    return allDiningHalls.end();
}
void Storage::removeMeal(int id)
{
    vector<Meal>::iterator i = findMeal(id);
    if (i == allMeals.end())
    {
        cerr << "Meal with id " << id << " doesn't exists :(" << endl;
        return;
    }
    allMeals.erase(i);
}
void Storage::removeDinningHall(int id)
{
    vector<DinningHall>::iterator i = findDiningHall(id);
    if (i == allDiningHalls.end())
    {
        cerr << "DinningHall with id " << id << " doesn't exists :(" << endl;
        return;
    }
    allDiningHalls.erase(i);
}

void Storage::MealActivation(int id, bool activation)
{
    vector<Meal>::iterator i = findMeal(id);
    if (i != allMeals.end())
        if (activation)
            findMeal(id)->activate();
        else
            findMeal(id)->deactivate();
    else
        cerr << "Meal with id " << id << " doesn't exists :(";
}
