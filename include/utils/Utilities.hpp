#ifndef UTILITIES_H
#define UTILITIES_H

enum class StudentOptions
{
    RESERVE_MEAL,
    CONFIRM_SHOPPING_CART,
    REMOVE_SHOPPING_CART_ITEM,
    BALANCE_INCREASE,
    CANCELLING_RESERVATION,
    RECENT_TRANSACTIONS,
    VIEW_RESERVATIONS,
    CHECK_BALANCE,
    EXIT
};

enum class ReserveDay
{
    SAT,
    SUN,
    MON,
    TUE,
    WED,
    THU,
    FRI
};

enum class MealType
{
    BREAKFAST,
    LUNCH,
    DINNER
};
enum class RStatus
{
    SUCCESS,
    CANCELLED,
    FAILED,
    NOT_PAID
};

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
#endif