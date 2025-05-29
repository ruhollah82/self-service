#include "interface/Panel.hpp"
#include "infrastructures/Storage.hpp"
#include "utils/Utilities.hpp"
#include "auth/SessionManager.hpp"
#include "roles/Student.hpp"
#include "foodservice/Meal.hpp"
#include "foodservice/DiningHall.hpp"
#include "foodservice/Reservation.hpp"
#include "payment/Transaction.hpp"
#include <algorithm>
#include <stdexcept>
/*
UTILITIEs should be added to program:
    - adding colorful printing functions
OPTIONS
    - should be loaded form files -- i didn't found a simple way to do this
*/

vector<pair<string, StudentOptions>> _menuOptions = {
    {"Reserve Meal", StudentOptions::RESERVE_MEAL},
    {"Confirm the Shopping Cart", StudentOptions::CONFIRM_SHOPPING_CART},
    {"Remove Shopping Cart Item", StudentOptions::REMOVE_SHOPPING_CART_ITEM},
    {"Balance Increase", StudentOptions::BALANCE_INCREASE},
    {"Cancelling Reservation", StudentOptions::CANCELLING_RESERVATION},
    {"Recent Transactions", StudentOptions::RECENT_TRANSACTIONS},
    {"View Reservations", StudentOptions::VIEW_RESERVATIONS},
    {"Check Balance", StudentOptions::CHECK_BALANCE},
    {"Exit", StudentOptions::EXIT},
};
Meal student_namespace::Panel::_chooseMeal(MealType mealType, ReserveDay reserveDay)
{
    vector<Meal> feasible_meals;

    std::copy_if(Storage::instance().allMeals.begin(), Storage::instance().allMeals.end(), std::back_inserter(feasible_meals), [&](const Meal &meal)
                 { return meal.getMealType() == mealType && meal.isActive() && meal.getReserveDay() == reserveDay; });

    cout << "Choose a meal:" << endl;
    for (int i = 0; i < feasible_meals.size(); i++)
    { // should be more generalized : also printing the price and side items
        cout << i + 1 << ". " << feasible_meals[i].getName() << endl;
    }
    int choice;
    cin >> choice;
    if (choice < 1 || choice > feasible_meals.size())
    {
        cout << "Invalid choice. Please try again." << endl;
        throw invalid_argument("Invalid choice");
    }
    return feasible_meals[choice - 1];
}
void student_namespace::Panel::showStudentInfo()
{
    student_namespace::SessionManager::instance().currentStudent()->print();
}
void student_namespace::Panel::showMenu()
{
    for (int i = 0; i < _menuOptions.size(); i++)
    {
        cout << i + 1 << ". " << _menuOptions[i].first << endl;
    }
}

void student_namespace::Panel::viewReservations()
{
    for (auto item : student_namespace::SessionManager::instance().currentStudent()->getReserves())
    {
        item.print(); // item is a reservation obj
    }
}

// TODO : Reservation should be added to Session Shoppingcart
void student_namespace::Panel::addReservation(const Reservation &reservation)
{
}

// NOT YET , AT THE END
void student_namespace::Panel::cancelReservation(int reservationID)
{
    // for (auto it = _reservations.begin(); it != _reservations.end(); ++it)
    // {
    //     if (it->getReservationID() == reservationID)
    //     {
    //         _reservations.erase(it);
    //         cout << "Reservation cancelled successfully!" << endl;
    //         return;
    //     }
    // }
    // cout << "Reservation not found!" << endl;
}

// ------------------------------------------------------------

// Check student balance
void student_namespace::Panel::checkBalance()
{
    cout << "Current Balance is: " << student_namespace::SessionManager::instance().currentStudent()->getBalance() << endl;
}

StudentOptions student_namespace::Panel::_mapping(int option)
{
    if (option < 1 || option > _menuOptions.size())
    {
        return StudentOptions::NONE;
    }
    return _menuOptions[option - 1].second;
}

void student_namespace::Panel::Action(int option)
{
    // logics of each case statement should be wrapped in a separated funciton
    switch (_mapping(option))
    {
    case StudentOptions::RESERVE_MEAL:
    {
        reserveMeal();

        break;
    }
    case StudentOptions::CONFIRM_SHOPPING_CART:
    {
        confirmShoppingCart();
        break;
    }
    case StudentOptions::REMOVE_SHOPPING_CART_ITEM:
    {
        removeShoppingCartItem();
        break;
    }
    case StudentOptions::BALANCE_INCREASE:
    {
        increaseBalance(); // Example amount
        break;
    }
    case StudentOptions::CANCELLING_RESERVATION:
    {
        cancelReservation(0); // Example reservation ID
        break;
    }
    case StudentOptions::RECENT_TRANSACTIONS:
    {
        viewRecentTransactions();
        break;
    }
    case StudentOptions::VIEW_RESERVATIONS:
    {
        viewReservations();
        break;
    }
    case StudentOptions::CHECK_BALANCE:
    {
        checkBalance();
        break;
    }
    case StudentOptions::EXIT:
    {
        exit();
        break;
    }
    default:
    {
        defaultOption();
        break;
    }
    }
}

// TODO: SHOULD BE REMOVED AND CUSTOMIZE FOR addReservation
void student_namespace::Panel::reserveMeal()
{
    MealType mealType = panel_utils::_chooseMealType();
    ReserveDay reserveDay = panel_utils::_chooseDay();
    DinningHall diningHall = panel_utils::_chooseDiningHall();
    Meal meal = _chooseMeal(mealType, reserveDay);
    // TODO: MAKE THE RESERVATION ID AUTO INCREMENTED
    // Reservation reservation(0, diningHall, meal, RStatus::NOT_PAID, time(nullptr));
    // this->_shoppingCart.addReservation(reservation);
    cout << "Meal added to shopping cart successfully" << endl;
}

void student_namespace::Panel::confirmShoppingCart()
{
    char choice;
    cout << "Do you want to confirm ? Y/N";
    cin >> choice;
    if (choice == 'Y' || choice == 'y')
    {
        // Payment logic
        // Transaction transaction = _shoppingCart.confirm();
        // _recentTransactions.push_back(transaction);
    }
    else
    {
        return;
    }
}
void student_namespace::Panel::removeShoppingCartItem()
{
}

void student_namespace::Panel::increaseBalance()
{
    float amount;
    cout << "Enter amount : " << endl;
    cin >> amount;
    student_namespace::SessionManager::instance().currentStudent()->setBalance(student_namespace::SessionManager::instance().currentStudent()->getBalance() + amount);
    cout << "Balance updated!" << endl;
}

// NOT YET
void student_namespace::Panel::viewRecentTransactions()
{
    // for (Transaction item : _recentTransactions)
    // {
    //     item.print();
    // }
}

void student_namespace::Panel::exit()
{
    /*
        showing the recent transactions
    */
    std::exit(0);
}

void student_namespace::Panel::defaultOption()
{
    // system("clear");
    cout << "Invalid option selected!" << endl;
    // sleep function
}