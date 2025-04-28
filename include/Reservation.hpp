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

    Meal getMeal() const;
    DiningHall getDiningHall() const;
    RStatus getStatus() const;
    time_t getCreatedAt() const;
    int getReservationID() const;
    time_t getCreatedAT() const;

    void setMeal(Meal meal);
    void setDiningHall(DiningHall dHall);
    void setStatus(RStatus status);
    void setCreatedAt(time_t createdAT);

private:
    int _reservationID;
    Student &_student;
    DiningHall _dHall;
    Meal _meal;
    RStatus _status;
    time_t _createdAT;
};
#endif // RESERVATION_HPP
