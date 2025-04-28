#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>
using namespace std;

enum class TransactionType
{
    Transfer,
    Payment
};

enum class TransactionStatus
{
    Pending,
    Completed,
    Failed,
};

class Transaction
{
private:
    int _transactionId;
    float _amount;
    TransactionType _type;
    TransactionStatus _status;
    time_t _createdAt;

public:
    Transaction(int id, float amt, TransactionType t, TransactionStatus s, time_t ts)
        : _transactionId(id), _amount(amt), _type(t), _status(s), _createdAt(ts) {}
    // Getters
    int getTransactionId() const { return _transactionId; }
    float getAmount() const { return _amount; }
    TransactionType getType() const { return _type; }
    TransactionStatus getStatus() const { return _status; }
    // modify this to returning the time and date format in string data type
    time_t getCreatedAt() const { return _createdAt; }

    // Setters
    void setTransactionId(int id) { _transactionId = id; }
    void setAmount(float amt) { _amount = amt; }
    void setType(TransactionType t) { _type = t; }
    void setStatus(TransactionStatus s) { _status = s; }
    void setCreatedAt(time_t ts) { _createdAt = ts; }
};

#endif