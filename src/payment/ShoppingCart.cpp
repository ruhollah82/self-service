#include "payment/ShoppingCart.hpp"
#include "payment/Transaction.hpp"
#include <ctime>

// Constructor
ShoppingCart::ShoppingCart(int cartID)
    : _cartID(cartID) {}

// Confirm checkout and return a Transaction object
Transaction ShoppingCart::confirm()
{
    // Placeholder logic for creating a Transaction
    float totalAmount = 0.0f;

    // Calculate the total amount from reservations
    for (const auto &reservation : _reservations)
    {
        // Assuming Reservation has a method to get the price of the meal
        totalAmount += reservation.getMeal().getPrice();
    }

    // Create a Transaction object
    Transaction transaction(
        _cartID, // Using cart ID as transaction ID for simplicity
        totalAmount,
        TransactionType::Payment,
        TransactionStatus::Completed,
        time(nullptr) // Current timestamp
    );

    // Clear reservations after checkout
    _reservations.clear();

    return transaction;
}

// Add a reservation to the shopping cart
void ShoppingCart::addReservation(const Reservation &reservation)
{
    _reservations.push_back(reservation);
}

// Remove a reservation from the shopping cart
void ShoppingCart::removeReservation(const int &ID)
{
    for (auto it = _reservations.begin(); it != _reservations.end(); ++it)
    {
        // Assuming Reservation has an equality operator or a unique ID for comparison
        // Ruhollah : Remove Reservation By getting ID not Reservation Object!!
        if (it->getReservationID() == ID)
        {
            _reservations.erase(it);
            break;
        }
    }
}

void ShoppingCart::viewShoppingCartItems()
{
    for (Reservation item : _reservations)
    {
        item.print();
    }
}
