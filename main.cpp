#include "foodservice/Reservation.hpp"
#include "roles/Student.hpp"
#include "foodservice/Meal.hpp"
#include "foodservice/DiningHall.hpp"
#include "interface/Panel.hpp"
#include "utils/Utilities.hpp"
#include "foodservice/RervationJsonSerialized.hpp"
#include "auth/SessionManager.hpp"
#include "nlohmann/json.hpp"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
using json = nlohmann::json;

int main()
{
    Reservation reserve(0, SessionManager::instace().currentStudent(), *(new DiningHall()), *(new Meal()), RStatus::NOT_PAID, time(nullptr));
    vector<Meal>
        mealList = {Meal(), Meal()};
    ofstream file("data.json", ios::out);
    json j = reserve;
    file << j;
    // json j = json::parse(file);
    // j.get_to(mealList);
    // for (auto &meal : mealList)
    // {
    //     meal.print();
    // }
    file.close();
    return 0;
}
