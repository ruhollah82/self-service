#ifndef UTILITIES_H
#define UTILITIES_H

enum class StudentOptions
{
    RESERVE_MEAL,
    CONFIRM_SHOPPING_CART,
    REMOVE_SHAPPING_CART_ITEM,
    BALANCE_INCREASE,
    CANLCELLING_RESERVATION,
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

#endif