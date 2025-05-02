#include "interface/Panel.hpp"
#include "infrastructures/Storage.hpp"
#include "utils/Utilities.hpp"
#include <algorithm>
#include <stdexcept>
/*
UTILITIEs should be added to program:
    - adding colorful printign functions
OPTIONS
    - should be loaded form files
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
    {"Exit", StudentOptions::EXIT}};

vector<pair<string, ReserveDay>> weekDays = {
    {"Sat", ReserveDay::SAT},
    {"Sun", ReserveDay::SUN},
    {"Mon", ReserveDay::MON},
    {"Tue", ReserveDay::TUE},
    {"Wed", ReserveDay::WED},
    {"Thu", ReserveDay::THU},
    {"Fri", ReserveDay::FRI}};

vector<pair<string, MealType>> mealTypes = {
    {"Breakfast", MealType::BREAKFAST},
    {"Lunch", MealType::LUNCH},
    {"Dinner", MealType::DINNER}};

MealType Panel::_chooseMealType()
{
    cout << "Choose a meal type:" << endl;
    for (int i = 0; i < mealTypes.size(); i++)
    {
        cout << i + 1 << ". " << mealTypes[i].first << endl;
    }
    int choice;
    cin >> choice;
    if (choice < 1 || choice > mealTypes.size())
    {
        cout << "Invalid choice. Please try again." << endl;
        throw invalid_argument("Invalid choice");
    }
    return mealTypes[choice - 1].second;
}

ReserveDay Panel::_chooseDay()
{
    cout << "Choose a day for reservation:" << endl;
    for (int i = 0; i < weekDays.size(); i++)
    {
        cout << i + 1 << ". " << weekDays[i].first << endl;
    }
    int choice;
    cin >> choice;
    if (choice < 1 || choice > weekDays.size())
    {
        cout << "Invalid choice. Please try again." << endl;
        throw invalid_argument("Invalid choice");
    }
    return weekDays[choice - 1].second;
}

Meal Panel::_chooseMeal(MealType mealType, ReserveDay reserveDay)
{
    vector<Meal> feasible_meals;

    std::copy_if(Storage::allMeals.begin(), Storage::allMeals.end(), std::back_inserter(feasible_meals), [&](const Meal &meal)
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

DiningHall Panel::_chooseDiningHall()
{
    cout << "Choose a dining hall:" << endl;
    for (int i = 0; i < Storage::allDiningHalls.size(); i++)
    {
        cout << i + 1 << ". " << Storage::allDiningHalls[i].getName() << endl;
    }
    int choice;
    cin >> choice;
    if (choice < 1 || choice > Storage::allDiningHalls.size())
    {
        cout << "Invalid choice. Please try again." << endl;
        throw invalid_argument("Invalid choice");
    }
    return Storage::allDiningHalls[choice - 1];
}
// Constructor
Panel::Panel(Student &student) : _student(student), _shoppingCart(student.getID())
{
}

// Show student information
void Panel::showStudentInfo()
{
    _student.print();
}
void Panel::showMenu()
{
    for (int i = 0; i < _menuOptions.size(); i++)
    {
        cout << i + 1 << ". " << _menuOptions[i].first << endl;
    }
}

// ------------------------------------------------------------
// ERROR WRONG RESERVATION --> panel::reservation != student.reservation
// ------------------------------------------------------------
// View all reservations
void Panel::viewReservations()
{
    // cout << "Reservations:" << endl;
    // for (const auto &reservation : _reservations)
    // {
    //     reservation.print();
    // }
}

// Add a reservation
void Panel::addReservation(const Reservation &reservation)
{
    // _reservations.push_back(reservation);
    // cout << "Reservation added successfully!" << endl;
}

// Cancel a reservation by ID
void Panel::cancelReservation(int reservationID)
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
void Panel::checkBalance()
{
    cout << "Current Balance: " << _student.getBalance() << endl;
}

StudentOptions Panel::_mapping(int option)
{
    if (option < 1 || option > _menuOptions.size())
    {
        return StudentOptions::EXIT;
    }
    return _menuOptions[option - 1].second;
}

void Panel::Action(int option)
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

void Panel::reserveMeal()
{
    MealType mealType = _chooseMealType();
    ReserveDay reserveDay = _chooseDay();
    DiningHall diningHall = _chooseDiningHall();
    Meal meal = _chooseMeal(mealType, reserveDay);
    // TODO: MAKE THE RESERVATION ID AUTO INCREMENTED
    Reservation reservation(0, this->_student, diningHall, meal, RStatus::NOT_PAID, time(nullptr));
    this->_shoppingCart.addReservation(reservation);
    cout << "Meal added to shopping cart successfully" << endl;
}

void Panel::confirmShoppingCart()
{
}
void Panel::removeShoppingCartItem()
{
    int ID;
    cout << "Enter the reservation ID you Wanna remove : " << endl;
    _shoppingCart.viewShoppingCartItems();
    cin >> ID;
    _shoppingCart.removeReservation(ID);
    cout << "Item has been removed !" << endl;
}

void Panel::increaseBalance()
{
    float amount;
    cout << "Enter the amount you want to add : ";
    cin >> amount;
    _student.setBalance(_student.getBalance() + amount);
    cout << "Balance updated!" << endl;
}

void Panel::viewRecentTransactions()
{
    cout << "Sharifi Ridi :)";
}

void Panel::exit()
{
    /*
        showing the recent transactions
    */
}

void Panel::defaultOption()
{
    // system("clear");
    cout << "Invalid option selected!" << endl;
    // sleep function
}