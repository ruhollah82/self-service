#ifndef CART_HPP
#define CART_HPP

#include "Reservation.hpp"
#include "Student.hpp"

using namespace std;

class Cart
{
private:
    int cart_id;
    Student student;
    vector<Reservation> reservations;

public:
};

#endif
