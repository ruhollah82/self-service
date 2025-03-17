#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include <string>
#include <ctime>

using namespace std;

class Transaction
{
private:
    int transaction_id;
    float amount;
    string type;
    string ststus;
    time_t timestamp;

public:
};

#endif
