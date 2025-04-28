#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "User.hpp"
#include <vector>
#include "Meal.hpp"
#include "Reservation.hpp"

using namespace std;

class Reservation;

class Student : public User
{
public:
    Student() : User(), _balance(0.0f), _isActive(false) {}
    Student(string studentID, string name, string lastName, string password);

    // Student-specific methods
    void reserveMeal();
    void cancelReservation();

    // Override print method
    void print() const override;

    // Getters
    int getUserID() const { return _userID; }
    bool isActive() const { return _isActive; }
    string getStudentID() const { return _studentID; }
    string getEmail() const { return _email; }
    string getPhone() const { return _phone; }
    float getBalance() const { return _balance; }

    // Setters
    void setStudentID(string studentID) { _studentID = studentID; }
    void setEmail(string email) { _email = email; }
    void setPhone(string phone) { _phone = phone; }
    void setBalance(float balance) { _balance = balance; }

    // Activation and deactivation
    void activate() { _isActive = true; }
    void deactivate() { _isActive = false; }

    // Other member functions
    bool checkPassword(string password);
    void setHashedPassword(string password);

private:
    string _studentID;
    string _email;
    string _phone;
    float _balance;
    bool _isActive;
    vector<Reservation> _reserves;
};

#endif // STUDENT_HPP