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
    for (auto i = allMeals.begin(); i != allMeals.end(); i++)
    {
        if (i->getMealID() == id)
        {
            return i;
        }
    }
    return allMeals.end();
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
    allMeals.erase(findMeal(id));
}
void Storage::removeDinningHall(int id)
{
    allDiningHalls.erase(findDiningHall(id));
}

void Storage::MealActivation(int id, bool activation)
{
    if (activation)
        findMeal(id)->activate();
    else
        findMeal(id)->deactivate();
}
