#ifndef PANEL_H
#define PANEL_H

#include "utils/Utilities.hpp"
#include <vector>
#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

class Student;
class Reservation;
class Meal;
class DinningHall;
namespace student_namespace
{
    class Panel
    {
    public:
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
        Meal _chooseMeal(MealType, ReserveDay);
        StudentOptions _mapping(int);
    };
}

namespace admin_namespace
{
    class Panel
    {
    public:
        void chooseCsvFile(fs::path);
        // Student findStudentByID(int);
        // Student findStudentByStudentID(string);
        // void createNewAdmin();
        // void banStudent(int);
        // void banStudent(string);
        // void removeAdmin(int);
        void displayAllMeals();
        void displayAllDininigHalls();
        void addNewMealIntractive();
        void addNewDiningHallIntractive();
        void removeMeal(int);
        void mealAcitvation(int, bool);
        void removeDiningHall(int);
        void showMenu();
        void action(int);
        // void editMealIntractive(int);
        // void editDiningHallIntractive(int);
        // void editStudentIntractiveByID(int);
        // void editStudentIntractiveByStudentID(string);

    private:
        // i don't think there should be anything
    };

}

namespace panel_utils
{
    ReserveDay _chooseDay();
    DinningHall _chooseDiningHall();
    MealType _chooseMealType();
}

#endif // PANEL_H