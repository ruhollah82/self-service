#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include "User.hpp"
#include "Meal.hpp"
#include "DiningHall.hpp"
enum class RStatus
{
    SUCCESS,
    CANCELLED,
    FAILED
};

class Reservation
{
public:
    Reservation();
    Reservation(int reservationID, const Student &student, const DiningHall &dHall, const Meal &meal, RStatus status, time_t createdAT);

private:
    int _reservationID;
    Student _student;
    DiningHall _dHall;
    Meal _meal;
    RStatus _status;
    time_t _createdAT;
};
#endif // RESERVATION_HPP
