#include "foodservice/Reservation.hpp"
#include "roles/Student.hpp"
#include "foodservice/Meal.hpp"
#include "foodservice/DiningHall.hpp"
#include "interface/Panel.hpp"
#include "utils/Utilities.hpp"
#include "foodservice/ReservationJsonSerialized.hpp"
#include "auth/SessionManager.hpp"
#include "nlohmann/json.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using json = nlohmann::json;

int main()
{
    // Reservation reserve(0, SessionManager::instace().currentStudent(), *(new DiningHall()), *(new Meal()), RStatus::NOT_PAID, time(nullptr));
    // vector<Meal>
    //     mealList = {Meal(), Meal()};
    // Student st("4011226319", "alireza", "sharifi", "12345");
    vector<Student> list = {Student("4011226319", "alireza", "sharifi", "12345"), Student("4011226319", "alireza", "sharifi", "12345")};
    ofstream file("data.json", ios::out);
    json j = list;
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
