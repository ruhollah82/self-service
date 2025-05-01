#include "foodservice/Reservation.hpp"
#include <iostream>
#include <ctime>
using namespace std;

// Default constructor
Reservation::Reservation()
    : _reservationID(0), _student(nullptr), _dHall(), _meal(), _status(RStatus::FAILED), _createdAT(time(nullptr))
{
}

Reservation::Reservation(int reservationID, Student &student, DiningHall &dHall, Meal &meal, RStatus status, time_t createdAT)
    : _reservationID(reservationID), _student(&student), _dHall(&dHall), _meal(&meal), _status(status), _createdAT(createdAT)
{
}

Meal Reservation::getMeal() const
{
    return *_meal;
}

DiningHall Reservation::getDiningHall() const
{
    return *_dHall;
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
void Reservation::setMeal(Meal &meal)
{
    _meal = &meal;
}
void Reservation::setDiningHall(DiningHall &dHall)
{
    _dHall = &dHall;
}
void Reservation::setStatus(RStatus status)
{
    _status = status;
}
void Reservation::setCreatedAt(time_t createdAT)
{
    _createdAT = createdAT;
}

void Reservation::print() const
{
    cout << "Reservation ID: " << this->getReservationID() << endl;
    cout << "Meal: " << this->getMeal().getName() << endl;
    cout << "Dining Hall: " << this->getDiningHall().getName() << endl;
    cout << "Status: " << (this->getStatus() == RStatus::SUCCESS ? "Success" : "Other") << endl;
    cout << "Created At: " << this->getCreatedAT() << endl;
    cout << "-----------------------------" << endl;
}