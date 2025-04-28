#include "../include/Reservation.hpp"
#include "../include/Student.hpp"
#include <ctime>

// Default constructor
Reservation::Reservation()
    : _reservationID(0), _dHall(), _student(*(new Student())), _meal(), _status(RStatus::FAILED), _createdAT(time(nullptr))
{
}

Meal Reservation::getMeal() const
{
    return _meal;
}

DiningHall Reservation::getDiningHall() const
{
    return _dHall;
}
RStatus Reservation::getStatus() const
{
    return _status;
}
time_t Reservation::getCreatedAT() const
{
    return _createdAT;
}
int Reservation::getReservationID() const
{
    return _reservationID;
}
void Reservation::setMeal(Meal meal)
{
    _meal = meal;
}
void Reservation::setDiningHall(DiningHall dHall)
{
    _dHall = dHall;
}
void Reservation::setStatus(RStatus status)
{
    _status = status;
}
void Reservation::setCreatedAt(time_t createdAT)
{
    _createdAT = createdAT;
}

// Getters and Setters

// Parameterized constructor
Reservation::Reservation(int reservationID, Student &student, const DiningHall &dHall, const Meal &meal, RStatus status, time_t createdAT)

    : _reservationID(reservationID), _dHall(dHall), _student(student), _meal(meal), _status(status), _createdAT(createdAT)
{
}