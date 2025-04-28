#include "../include/Panel.hpp"
#include "../include/Utilities.hpp"
/*
UTILITIEs should be added to program:
    - adding colorful printign functions
*/

vector<pair<string, StudentOptions>> Panel::_MenuOptions = {
    {"Reserve Meal", StudentOptions::RESERVE_MEAL},
    {"Confirm the Shopping Cart", StudentOptions::CONFIRM_SHOPPING_CART},
    {"Remove Shopping Cart Item", StudentOptions::REMOVE_SHAPPING_CART_ITEM},
    {"Balance Increase", StudentOptions::BALANCE_INCREASE},
    {"Cancelling Reservation", StudentOptions::CANLCELLING_RESERVATION},
    {"Recent Transactions", StudentOptions::RECENT_TRANSACTIONS},
    {"View Reservations", StudentOptions::VIEW_RESERVATIONS},
    {"Check Balance", StudentOptions::CHECK_BALANCE},
    {"Exit", StudentOptions::EXIT}};

// Constructor
Panel::Panel(Student &student) : _student(student) {}

// Show student information
void Panel::showStudentInfo()
{
    _student.print();
}
void Panel::showMenu()
{
    for (int i = 0; i < Panel::_MenuOptions.size(); i++)
    {
        cout << i + 1 << ". " << Panel::_MenuOptions[i].first << endl;
    }
}

// View all reservations
void Panel::viewReservations()
{
    cout << "Reservations:" << endl;
    for (const auto &reservation : _reservations)
    {
        reservation.print();
    }
}

// Add a reservation
void Panel::addReservation(const Reservation &reservation)
{
    _reservations.push_back(reservation);
    cout << "Reservation added successfully!" << endl;
}

// Cancel a reservation by ID
void Panel::cancelReservation(int reservationID)
{
    for (auto it = _reservations.begin(); it != _reservations.end(); ++it)
    {
        if (it->getReservationID() == reservationID)
        {
            _reservations.erase(it);
            cout << "Reservation cancelled successfully!" << endl;
            return;
        }
    }
    cout << "Reservation not found!" << endl;
}

// Check student balance
void Panel::checkBalance()
{
    cout << "Current Balance: " << _student.getBalance() << endl;
}

StudentOptions Panel::_mapping(int option)
{
    if (option < 1 || option > _MenuOptions.size())
    {
        return StudentOptions::EXIT;
    }
    return _MenuOptions[option - 1].second;
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
    case StudentOptions::REMOVE_SHAPPING_CART_ITEM:
    {
        removeShoppingCartItem();
        break;
    }
    case StudentOptions::BALANCE_INCREASE:
    {
        increaseBalance(100.0f); // Example amount
        break;
    }
    case StudentOptions::CANLCELLING_RESERVATION:
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
}

void Panel::confirmShoppingCart()
{
}
void Panel::removeShoppingCartItem()
{
}

void Panel::increaseBalance(float amount)
{
    /*
        processing the payment gateway and creating the transaction fucntion
    */
}

void Panel::viewRecentTransactions()
{
    /*
        showing the recent transactions
    */
}

void Panel::exit()
{
    /*
        showing the recent transactions
    */
}

void Panel::defaultOption()
{
    system("clear");
    cout << "Invalid option selected!" << endl;
    // sleep function
}