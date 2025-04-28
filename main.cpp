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
    Meal meal();

    DiningHall diningHall("Main Dining Hall", "123 University St.");
    // Create a sample Reservation object
    Reservation reservation(2, student, diningHall, meal, RStatus::SUCCESS, time(0));

    // Create a sample DiningHall object
    diningHall.addMeal(meal);

    // Output sample data
    cout << "Student: " << student.getName() << endl;
    cout << "Meal: " << meal.getName() << " - $" << meal.getPrice() << endl;
    cout << "Reservation: " << reservation.getDate() << " at " << reservation.getTime() << endl;
    cout << "Dining Hall: " << diningHall.getName() << " located at " << diningHall.getLocation() << endl;
    return 0;
}
