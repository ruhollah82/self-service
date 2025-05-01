#ifndef DININGHALL_HPP
#define DININGHALL_HPP

#include <string>

using namespace std;

class DiningHall
{
public:
    DiningHall();
    DiningHall(int, string, string, int);

    // Getters
    int getHallID() const { return _hallID; }
    string getName() const { return _name; }
    string getAddress() const { return _address; }
    int getCapacity() const { return _capacity; }

    // Setters
    void setHallID(int hallID) { _hallID = hallID; }
    void setName(string name) { _name = name; }
    void setAddress(string address) { _address = address; }
    void setCapacity(int capacity) { _capacity = capacity; }

    // Other Methods:
    void print();

private:
    int _hallID;
    string _name;
    string _address;
    int _capacity;
};

#endif // DININGHALL_HPP
