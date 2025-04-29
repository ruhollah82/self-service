#ifndef SHOPPINGCART_HPP
#define SHOPPINGCART_HPP

#include "../roles/Student.hpp"
#include "../foodservice/Reservation.hpp"
#include <vector>

using namespace std;

class Transaction; // Forward declaration for Transaction class
class Rervation;
class ShoppingCart
{
public:
    ShoppingCart(int cartID);

    // Methods
    Transaction confirm();
    void addReservation(const Reservation &reservation);
    void removeReservation(const Reservation &reservation);

private:
    int _cartID; // equal to user_id
    vector<Reservation> _reservations;
};

#endif // SHOPPINGCART_HPP