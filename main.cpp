#include "include/User.hpp"
#include "include/Meal.hpp"
#include "include/Reservation.hpp"
#include "include/DiningHall.hpp"

#include <iostream>

using namespace std;

int main()
{
    // Create a sample Student object
    Student student("4011226319", "alireza", "sharifi", "1234");

    // Create a sample Meal object
    Meal meal;

    DiningHall diningHall;
    // Create a sample Reservation object
    Reservation reservation(2, student, diningHall, meal, RStatus::SUCCESS, time(0));

    return 0;
}
