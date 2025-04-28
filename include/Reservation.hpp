#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include "Meal.hpp"
#include "DiningHall.hpp"

enum class RStatus
{
    SUCCESS,
    CANCELLED,
    FAILED
};

class Student;

class Reservation
{
public:
    Reservation();
    Reservation(int reservationID, Student &student, const DiningHall &dHall, const Meal &meal, RStatus status, time_t createdAT);

    // Getters
    int getReservationID() const { return _reservationID; }
    Student &getStudent() const { return _student; }
    const DiningHall &getDiningHall() const { return _dHall; }
    const Meal &getMeal() const { return _meal; }
    RStatus getStatus() const { return _status; }
    time_t getCreatedAT() const { return _createdAT; }

    // Setters
    void setReservationID(int reservationID) { _reservationID = reservationID; }
    void setDiningHall(const DiningHall &dHall) { _dHall = dHall; }
    void setMeal(const Meal &meal) { _meal = meal; }
    void setStatus(RStatus status) { _status = status; }
    void setCreatedAT(time_t createdAT) { _createdAT = createdAT; }

private:
    int _reservationID;
    Student &_student;
    DiningHall _dHall;
    Meal _meal;
    RStatus _status;
    time_t _createdAT;
};
#endif // RESERVATION_HPP
