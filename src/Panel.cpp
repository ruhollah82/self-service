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
        cout << "Reservation ID: " << reservation.getReservationID() << endl;
        cout << "Meal: " << reservation.getMeal().getName() << endl;
        cout << "Dining Hall: " << reservation.getDiningHall().getName() << endl;
        cout << "Status: " << (reservation.getStatus() == RStatus::SUCCESS ? "Success" : "Other") << endl;
        cout << "Created At: " << reservation.getCreatedAT() << endl;
        cout << "-----------------------------" << endl;
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
        cout << "Reserving a meal..." << endl;
        /*
            creating a reservation instance and then Add it to Shoping cart.
        */

        break;
    }
    case StudentOptions::CONFIRM_SHOPPING_CART:
    {
        cout << "Confirming the shopping cart..." << endl;
        // Placeholder logic for confirming the shopping cart
        // You can integrate this with the ShoppingCart class
        break;
    }
    case StudentOptions::REMOVE_SHAPPING_CART_ITEM:
    {
        cout << "Removing an item from the shopping cart..." << endl;
        // Placeholder logic for removing an item from the shopping cart
        break;
    }
    case StudentOptions::BALANCE_INCREASE:
    {
        cout << "Increasing balance..." << endl;
        float amount;
        cout << "Enter the amount to add to your balance: ";
        cin >> amount;
        _student.setBalance(_student.getBalance() + amount);
        cout << "Balance updated successfully!" << endl;
        break;
    }
    case StudentOptions::CANLCELLING_RESERVATION:
    {
        cout << "Cancelling a reservation..." << endl;
        int reservationID;
        cout << "Enter the reservation ID to cancel: ";
        cin >> reservationID;
        cancelReservation(reservationID);
        break;
    }
    case StudentOptions::RECENT_TRANSACTIONS:
    {
        cout << "Viewing recent transactions..." << endl;
        // Placeholder logic for viewing recent transactions
        // You can integrate this with the Transaction class
        break;
    }
    case StudentOptions::VIEW_RESERVATIONS:
    {
        cout << "Viewing reservations..." << endl;
        viewReservations();
        break;
    }
    case StudentOptions::CHECK_BALANCE:
    {
        cout << "Checking balance..." << endl;
        checkBalance();
        break;
    }
    case StudentOptions::EXIT:
    {
        cout << "Exiting the panel..." << endl;
        break;
    }
    default:
    {
        cout << "Invalid option selected!" << endl;
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
