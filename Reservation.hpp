#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include "Student.hpp"
#include "Meal.hpp"
#include <ctime>

using namespace std;

class Meal;

class Reservation
{
private:
    int reservation_id;
    Student *student;
    Meal *meal;
    string status;
    time_t created_at;

public:
};

#endif // RESERVATION_HPP
