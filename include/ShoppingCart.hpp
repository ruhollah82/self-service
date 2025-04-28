#ifndef SHOPPINGCART_HPP
#define SHOPPINGCART_HPP

#include "User.hpp"
#include "Reservation.hpp"
#include <vector>

using namespace std;

class Transaction; // Forward declaration for Transaction class

class ShoppingCart
{
public:
    ShoppingCart(int cartID, Student student);

    // Methods
    Transaction confirm();
    void addReservation(const Reservation &reservation);
    void removeReservation(const Reservation &reservation);

private:
    int _cartID;
    Student _student;
    vector<Reservation> _reservations;
};

#endif // SHOPPINGCART_HPP