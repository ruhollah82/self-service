#ifndef UTILITIES_H
#define UTILITIES_H

#include <nlohmann/json.hpp>
using json = nlohmann::json;
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

enum class SessionStatus
{
    AUTHENTICATED,
    ANONYMOUS
};

NLOHMANN_JSON_SERIALIZE_ENUM(
    SessionStatus,
    {
        {SessionStatus::AUTHENTICATED, "authenticated"},
        {SessionStatus::ANONYMOUS, "anonymous"},
    })

NLOHMANN_JSON_SERIALIZE_ENUM(
    MealType,
    {
        {MealType::BREAKFAST, "Breakfast"},
        {MealType::LUNCH, "Lunch"},
        {MealType::DINNER, "Dinner"},
    })

NLOHMANN_JSON_SERIALIZE_ENUM(
    ReserveDay,
    {
        {ReserveDay::SAT, "Saturday"},
        {ReserveDay::SUN, "Sunday"},
        {ReserveDay::MON, "Monday"},
        {ReserveDay::TUE, "Tuesday"},
        {ReserveDay::WED, "Wednesday"},
        {ReserveDay::THU, "Thursday"},
        {ReserveDay::FRI, "Friday"},

    })

NLOHMANN_JSON_SERIALIZE_ENUM(
    RStatus,
    {
        {RStatus::SUCCESS, "Success"},
        {RStatus::CANCELLED, "Cancelled"},
        {RStatus::FAILED, "Failed"},
        {RStatus::NOT_PAID, "Not Paid"},
    })
NLOHMANN_JSON_SERIALIZE_ENUM(
    TransactionType,
    {
        {TransactionType::Transfer, "Transfer"},
        {TransactionType::Payment, "Payment"},
    })

NLOHMANN_JSON_SERIALIZE_ENUM(
    TransactionStatus,
    {
        {TransactionStatus::Pending, "Pending"},
        {TransactionStatus::Completed, "Completed"},
        {TransactionStatus::Failed, "Failed"},
    })

#endif