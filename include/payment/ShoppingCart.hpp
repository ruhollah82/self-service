#ifndef SHOPPINGCART_HPP
#define SHOPPINGCART_HPP

#include "../foodservice/Reservation.hpp"
#include <vector>

using namespace std;

class Transaction; // Forward declaration for Transaction class
class ShoppingCart
{
public:
    // Methods
    Transaction confirm();
    void addReservation(const Reservation &reservation);
    void removeReservation(const int &ID);
    void viewShoppingCartItems();
    void clear();
    vector<Reservation> getReservations() const
    {
        return this->_reservations;
    }

private:
    vector<Reservation> _reservations;
};

#endif // SHOPPINGCART_HPP