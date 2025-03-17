#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include "User.hpp"

using namespace std;

class Student : public User
{
private:
    string student_id;
    float balance;

public:
};

#endif // STUDENT_HPP
