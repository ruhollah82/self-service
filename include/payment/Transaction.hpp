#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "../utils/Utilities.hpp"
#include <nlohmann/json.hpp>
#include <string>
#include <ctime>
using namespace std;
using json = nlohmann::json;

class Transaction
{
private:
    int _transactionId;
    string _trackingCode;
    float _amount;
    TransactionType _type;
    TransactionStatus _status;
    time_t _createdAt;

public:
    Transaction(int id, string tc, float amt, TransactionType t, TransactionStatus s, time_t ts)
        : _transactionId(id), _trackingCode(tc), _amount(amt), _type(t), _status(s), _createdAt(ts) {}
    // Getterstran
    int getTransactionId() const { return _transactionId; }
    float getAmount() const { return _amount; }
    TransactionType getType() const { return _type; }
    TransactionStatus getStatus() const { return _status; }
    // modify this to returning the time and date format in string data type
    time_t getCreatedAt() const { return _createdAt; }
    string getTrackingCode() const { return this->_trackingCode; }
    // Setters
    void setTransactionId(int id) { _transactionId = id; }
    void setAmount(float amt) { _amount = amt; }
    void setType(TransactionType t) { _type = t; }
    void setStatus(TransactionStatus s) { _status = s; }
    void setCreatedAt(time_t ts) { _createdAt = ts; }
    void setTrackingCode(const string &tc) { this->_trackingCode = tc; }

    void print()
    {
        char timeBuffer[80];
        struct tm *timeInfo = localtime(&_createdAt);
        strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", timeInfo);
        json j = json{
            {"type", _type},
            {"status", _status},
        };
        cout << "Transaction ID: " << _transactionId << endl;
        cout << "Amount: $" << _amount << endl;
        cout << "Type: " << j["type"] << endl;
        cout << "Status: " << j["status"] << endl;
        cout << "Created At: " << timeBuffer << endl;
        cout << "------------------------ " << endl;
    }
};

#endif