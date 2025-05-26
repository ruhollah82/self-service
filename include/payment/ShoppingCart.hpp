#ifndef SHOPPINGCART_HPP
#define SHOPPINGCART_HPP

#include "foodservice/Reservation.hpp"
#include "foodservice/ReservationJsonSerialized.hpp"
#include <nlohmann/json.hpp>
#include <vector>

using namespace std;
using js = nlohmann::json;

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
namespace nlohmann
{
    template <>
    struct adl_serializer<ShoppingCart>
    {
        static void to_json(json &j, const ShoppingCart &rh)
        {
            j = json{
                {"reserves", rh.getReservations()},
            };
        }
        static void from_json(const json &j, ShoppingCart &rh)
        {
            auto reserves = j.at("reserves").get<vector<Reservation>>();
            for (auto r : reserves)
                rh.addReservation(r);
        }
    };
}

#endif // SHOPPINGCART_HPP