#include "../include/Reservation.hpp"
#include <ctime>
// Default constructor
Reservation::Reservation()
    : _reservationID(0), _student(Student()), _dHall(DiningHall()), _meal(Meal()), _status(RStatus::FAILED), _createdAT(time(nullptr))
{
}

// Parameterized constructor
Reservation::Reservation(int reservationID, const Student &student, const DiningHall &dHall, const Meal &meal, RStatus status, time_t createdAT)
    : _reservationID(reservationID), _student(student), _dHall(dHall), _meal(meal), _status(status), _createdAT(createdAT)
{
}