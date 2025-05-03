#ifndef PANEL_H
#define PANEL_H

#include "../utils/Utilities.hpp"
#include "../roles/Student.hpp"
#include "../payment/ShoppingCart.hpp"
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
    void checkBalance();
    void viewReservations();
    void addReservation(const Reservation &reservation);
    void reserveMeal();
    void confirmShoppingCart();
    void removeShoppingCartItem();
    void increaseBalance();
    void viewRecentTransactions();
    void cancelReservation(int reservationID);
    void exit();
    void defaultOption();

private:
    ReserveDay _chooseDay();
    Meal _chooseMeal(MealType, ReserveDay);
    DiningHall _chooseDiningHall();
    MealType _chooseMealType();
    StudentOptions _mapping(int);
    Student &_student;
    // should be save in a file and load it from there too
    ShoppingCart _shoppingCart;
    vector<Transaction> _recentTransactions;
};

#endif // PANEL_H