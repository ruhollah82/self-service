#include "interface/Panel.hpp"
#include "foodservice/Filling.hpp"
#include "foodservice/Meal.hpp"
#include "foodservice/DiningHall.hpp"
#include "foodservice/Reservation.hpp"
#include "infrastructures/Storage.hpp"
#include <vector>
using namespace std;
using namespace admin_namespace;
using namespace filling;

vector<pair<string, AdminOptions>> options = {
    {"Choose Csv File", AdminOptions::CHOOSE_CSV_FILE},
    {"Add Meal", AdminOptions::ADD_MEALS},
    {"Add DinningHall", AdminOptions::ADD_DINNINGHALL},
    {"Remove Meal", AdminOptions::REMOVE_MEALS},
    {"Remove DinningHall", AdminOptions::REMOVE_DINNINGHALL},
    {"Meal Activation", AdminOptions::MEAL_ACTIVATION},
    {"Display All Meals", AdminOptions::DISPLAY_ALL_MEALS},
    {"Display All DinningHalls", AdminOptions::DISPLAY_ALL_DINNINGHALLS},
    {"Exit", AdminOptions::EXIT},
};

void Panel::displayAllMeals()
{
    for (Meal item : FoodService<Meal>::giveAll())
    {
        item.print();
    }
}
void Panel::displayAllDininigHalls()
{
    for (DinningHall item : FoodService<DinningHall>::giveAll())
    {
        item.print();
    }
}

void Panel::addNewMealIntractive()
{
    Meal meal;
    meal.input();
    Storage::instance().addMeal(meal);
    FoodService<Meal>::save(Storage::instance().allMeals);
}

void Panel::addNewDiningHallIntractive()
{
    DinningHall d;
    d.input();
    Storage::instance().addDinningHall(d);
    FoodService<DinningHall>::save(Storage::instance().allDiningHalls);
}

void Panel::mealAcitvation(int id, bool activation)
{
    Storage::instance().MealActivation(id, activation);
    FoodService<Meal>::save(Storage::instance().allMeals);
}

void Panel::removeDiningHall(int id)
{
    Storage::instance().removeDinningHall(id);
    FoodService<DinningHall>::save(Storage::instance().allDiningHalls);
}
void Panel::removeMeal(int id)
{
    Storage::instance().removeMeal(id);
    FoodService<Meal>::save(Storage::instance().allMeals);
}

void Panel::showMenu()
{
    for (int i = 0; i < options.size(); i++)
    {
        cout << i + 1 << ". " << options[i].first << endl;
    }
}
AdminOptions _mapping(int option)
{
    if (option < 1 || option > options.size())
    {
        return AdminOptions::NONE;
    }
    else
        return options[option - 1].second;
}

void Panel::action(int option)
{
    switch (_mapping(option))
    {
    case AdminOptions::ADD_MEALS:
    {
        this->addNewMealIntractive();
        break;
    }
    case AdminOptions::ADD_DINNINGHALL:
    {
        this->addNewDiningHallIntractive();
        break;
    }
    case AdminOptions::REMOVE_MEALS:
    {
        cout << "Enter the ID of Meal you Want to delete: ";
        int id;
        cin >> id;
        this->removeMeal(id);
        break;
    }
    case AdminOptions::REMOVE_DINNINGHALL:
    {
        cout << "Enter the ID of DinningHall you Want to delete: ";
        int id;
        cin >> id;
        this->removeDiningHall(id);
        break;
    }
    case AdminOptions::MEAL_ACTIVATION:
    {
        cout << "Enter the Meal ID that you want to modify: ";
        int id, opt;
        cin >> id;
        cout << "1. Activate\n2. DeActivate\n>>> ";
        cin >> opt;
        if (opt != 1 && opt != 2)
        {
            cerr << "invalid option :(" << endl;
            break;
        }
        this->mealAcitvation(id, ((opt == 1) ? true : false));
        break;
    }
    case AdminOptions::DISPLAY_ALL_DINNINGHALLS:
    {
        this->displayAllMeals();
        break;
    }
    case AdminOptions::DISPLAY_ALL_MEALS:
    {
        this->displayAllMeals();
        break;
    }
    case AdminOptions::EXIT:
    {
        cout << "GOOD BYE :)";
        exit(0);
        break;
    }
    default:
    {
        cerr << "invalid Option :(" << endl;
        break;
    }
    }
}