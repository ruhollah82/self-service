#include "../include/Reservation.hpp"
#include "../include/User.hpp"
#include <ctime>
// Default constructor
Reservation::Reservation()
    : _reservationID(0), _dHall(), _student(*(new Student())), _meal(), _status(RStatus::FAILED), _createdAT(time(nullptr))
{
}

// Parameterized constructor
Reservation::Reservation(int reservationID, Student &student, const DiningHall &dHall, const Meal &meal, RStatus status, time_t createdAT)

    : _reservationID(reservationID), _dHall(dHall), _student(student), _meal(meal), _status(status), _createdAT(createdAT)
{
}