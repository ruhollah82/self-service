#include "infrastructures/Storage.hpp"
#include "nlohmann/json.hpp"

vector<Meal> Storage::allMeals = {};
vector<DiningHall> Storage::allDiningHalls = {};
int Storage::_mealIDCounter = 0;
int Storage::_diningHallIDCounter = 0;
void Storage::initialize()
{
    allMeals = {
        Meal("Pasta", 10.5, {"Salad", "Juice"}),
        Meal("Pizza", 8.0, {"Garlic Bread", "Soda"})};

    allDiningHalls = {
        DiningHall(1, "Main Hall", "123 Street", 100),
        DiningHall(2, "East Hall", "456 Avenue", 80)};
}