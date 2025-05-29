#include "interface/Panel.hpp"
#include "infrastructures/Storage.hpp"

vector<pair<string, ReserveDay>> weekDays = {
    {"Sat", ReserveDay::SAT},
    {"Sun", ReserveDay::SUN},
    {"Mon", ReserveDay::MON},
    {"Tue", ReserveDay::TUE},
    {"Wed", ReserveDay::WED},
    {"Thu", ReserveDay::THU},
    {"Fri", ReserveDay::FRI}};

vector<pair<string, MealType>> mealTypes = {
    {"Breakfast", MealType::BREAKFAST},
    {"Lunch", MealType::LUNCH},
    {"Dinner", MealType::DINNER}};

MealType panel_utils::_chooseMealType()
{
    cout << "Choose a meal type:" << endl;
    for (int i = 0; i < mealTypes.size(); i++)
    {
        cout << i + 1 << ". " << mealTypes[i].first << endl;
    }
    int choice;
    cin >> choice;
    if (choice < 1 || choice > mealTypes.size())
    {
        cout << "Invalid choice. Please try again." << endl;
        throw invalid_argument("Invalid choice");
    }
    return mealTypes[choice - 1].second;
}

ReserveDay panel_utils::_chooseDay()
{
    cout << "Choose a day for reservation:" << endl;
    for (int i = 0; i < weekDays.size(); i++)
    {
        cout << i + 1 << ". " << weekDays[i].first << endl;
    }
    int choice;
    cin >> choice;
    if (choice < 1 || choice > weekDays.size())
    {
        cout << "Invalid choice. Please try again." << endl;
        throw invalid_argument("Invalid choice");
    }
    return weekDays[choice - 1].second;
}

DinningHall panel_utils::_chooseDiningHall()
{
    cout << "Choose a dining hall:" << endl;
    for (int i = 0; i < Storage::instance().allDiningHalls.size(); i++)
    {
        cout << i + 1 << ". " << Storage::instance().allDiningHalls[i].getName() << endl;
    }
    int choice;
    cin >> choice;
    if (choice < 1 || choice > Storage::instance().allDiningHalls.size())
    {
        cout << "Invalid choice. Please try again." << endl;
        throw invalid_argument("Invalid choice");
    }
    return Storage::instance().allDiningHalls[choice - 1];
}
