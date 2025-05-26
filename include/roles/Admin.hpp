#ifndef ADMIN_HPP
#define ADMIN_HPP

#include "User.hpp"

class Admin : public User
{
public:
    Admin();
    Admin(int id, string name, string lastName, string password);

    // Admin-specific methods
    void manageUsers();
    void manageReservations();
    void manageMeals();

    // Override print method
    void print() const override;
};

#endif // ADMIN_HPP