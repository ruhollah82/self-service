#include "include/Reservation.hpp"
#include "include/Student.hpp"
#include "include/Meal.hpp"
#include "include/DiningHall.hpp"
#include "include/Panel.hpp"

#include <iostream>

using namespace std;

int main()
{
    // Create a sample Student object
    Student student;

    // Create a sample Meal object
    Meal meal;

    DiningHall diningHall;
    // Create a sample Reservation object
    Reservation reservation(2, student, diningHall, meal, RStatus::SUCCESS, time(0));
    Panel panel(student);

    return 0;
}
