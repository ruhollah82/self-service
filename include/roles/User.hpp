#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class User
{

protected:
    int _userID;
    string _name;
    string _lastName;
    string _hashedPassword;

public:
    User();
    User(string name, string lastName, string hashedPassword);

    // Virtual destructor for proper cleanup in derived classes
    virtual ~User() {}

    // Common methods
    virtual void print() const;

    // Getters
    int getID() const { return _userID; }
    string getName() const { return _name; }
    string getLastName() const { return _lastName; }
    string getHashedPassword() const { return _hashedPassword; }

    // Setters
    void setID(int id) { _userID = id; }
    void setName(string name) { _name = name; }
    void setLastName(string lastName) { _lastName = lastName; }
    void setPassword(string password);
    // Other member functions
    bool checkPassword(string password);
    void setHashedPassword(string);
};

#endif // USER_HPP