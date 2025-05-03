#ifndef RESERVATION_HPP
#define RESERVATION_HPP
#include "DiningHall.hpp"
#include "Meal.hpp"
#include "utils/Utilities.hpp"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Reservation
{
public:
    Reservation();
    Reservation(int, DiningHall &, Meal &, RStatus, time_t);

    Meal getMeal() const;
    DiningHall getDiningHall() const;
    RStatus getStatus() const;
    time_t getCreatedAt() const;
    int getReservationID() const;
    time_t getCreatedAT() const;
    // Student &getStudent() const { return *_student; }

    void setReservationID(int id) { this->_reservationID = id; };
    void setMeal(Meal &meal);
    void setDiningHall(DiningHall &dHall);
    void setStatus(RStatus status);
    void setCreatedAt(time_t createdAT);
    // void setStudent(Student *student) { this->_student = student; };

    void print() const;

private:
    int _reservationID;
    // Student *_student; // Change reference to pointer
    DiningHall *_dHall;
    Meal *_meal;
    RStatus _status;
    time_t _createdAT;
};

#endif // RESERVATION_HPP
