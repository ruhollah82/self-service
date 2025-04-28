#include "../include/Reservation.hpp"
#include "../include/User.hpp"
#include <ctime>
// Default constructor
Reservation::Reservation()
    : _reservationID(0), _dHall(new DiningHall()), _student(new Student()), _meal(new Meal()), _status(RStatus::FAILED), _createdAT(time(nullptr))
{
}

// Parameterized constructor
Reservation::Reservation(int reservationID, const Student &student, const DiningHall &dHall, const Meal &meal, RStatus status, time_t createdAT)

    : _reservationID(reservationID), _dHall(new DiningHall(dHall)), _student(new Student(student)), _meal(new Meal(meal)), _status(status), _createdAT(createdAT)
{
}