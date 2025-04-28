#ifndef PANEL_H
#define PANEL_H

#include "Student.hpp"
#include "Reservation.hpp"
#include "Meal.hpp"
#include "Utilities.hpp"
#include <vector>
#include <iostream>

using namespace std;

class Panel
{
public:
    Panel(Student &student);
    // Methods
    void Action(int);
    void showMenu();
    void showStudentInfo();
    void viewReservations();
    void addReservation(const Reservation &reservation);
    void reserveMeal();
    void confirmShoppingCart();
    void removeShoppingCartItem();
    void increaseBalance(float amount);
    void viewRecentTransactions();
    void cancelReservation(int reservationID);
    void checkBalance();

private:
    StudentOptions _mapping(int);
    Student &_student;
    static vector<pair<string, StudentOptions>> _MenuOptions;
    vector<Reservation> _reservations;
};

#endif // PANEL_H