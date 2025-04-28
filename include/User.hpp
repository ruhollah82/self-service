#ifndef USER_HPP
#define USER_HPP

#include <string> // Include necessary headers here
#include <vector>
#include "Meal.hpp"
using namespace std;

class Reservation;
// Class definitions and declarations will go here
class Student
{
public:
    Student() {}
    Student(string studentID, string name, string lastName, string hashedPassword);
    void print();
    void reserverMeal();
    void cancelReservation();

    // Getters
    int getUserID() const { return _userID; }
    bool isActive() const { return _isActive; }
    string getStudentID() const { return _studentID; }
    string getName() const { return _name; }
    string getLastName() const { return _lastName; }
    string getEmail() const { return _email; }
    string getPhone() const { return _phone; }
    float getBalance() const { return _balance; }

    // Setters
    // void setUserID(int userID);
    void setStudentID(string studentID) { _studentID = studentID; }
    void setName(string name) { _name = name; }
    void setLastName(string lastName) { _lastName = lastName; }
    void setEmail(string email) { _email = email; }
    void setPhone(string phone) { _phone = phone; }
    void setBalance(float balance) { _balance = balance; }

    // Activation and deactivation
    void activate();
    void deactivate();

    // Other member functions
    bool checkPassword(string password);
    void setHashedPassword(string password);

private:
    int _userID;
    string _studentID;
    string _name;
    string _lastName;
    string _email;
    string _hashedPassword;
    string _phone;
    float _balance;
    bool _isActive;
    vector<Reservation> _reserves;
};

#endif // ROLES_HPP