#ifndef RESERVATION_HPP
#define RESERVATION_HPP
#include "utils/Utilities.hpp"
#include "infrastructures/Storage.hpp"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Meal;
class DinningHall;
class Reservation
{
public:
    Reservation();
    Reservation(int, DinningHall &, Meal &, RStatus, time_t);

    Meal getMeal() const;
    DinningHall getDiningHall() const;
    RStatus getStatus() const;
    time_t getCreatedAt() const;
    int getReservationID() const;
    time_t getCreatedAT() const;
    // Student &getStudent() const { return *_student; }

    void setReservationID(int id) { this->_reservationID = id; };
    void setMeal(Meal &meal);
    void setDiningHall(DinningHall &dHall);
    void setStatus(RStatus status);
    void setCreatedAt(time_t createdAT);
    // void setStudent(Student *student) { this->_student = student; };

    void print() const;

private:
    int _reservationID;
    // Student *_student; // Change reference to pointer
    DinningHall *_dHall;
    Meal *_meal;
    RStatus _status;
    time_t _createdAT;
};

namespace nlohmann
{
    template <>
    struct adl_serializer<Reservation>
    {
        static void to_json(json &j, const Reservation &reserve)
        {
            j = json{
                {"created-at", reserve.getCreatedAT()},
                {"id", reserve.getReservationID()},
                {"status", reserve.getStatus()},
                // {"student-id", reserve.getStudent().getID()},
                {"meal-id", reserve.getMeal().getMealID()},
                {"dininghall-id", reserve.getDiningHall().getHallID()}};
        }

        static void from_json(const json &j, Reservation &reserve)
        {
            reserve.setStatus(j.at("status").get<RStatus>());
            reserve.setCreatedAt(j.at("created-at").get<time_t>());
            reserve.setReservationID(j.at("id").get<int>());
            // reserve.setStudent(SessionManager::instace().currentStudent());
            int meal_id = j.at("meal-id").get<int>();
            int dhall_id = j.at("dininghall-id").get<int>();

            reserve.setMeal(*Storage::instance().findMeal(meal_id));
            reserve.setDiningHall(*Storage::instance().findDiningHall(dhall_id));
        }
    };
}

#endif // RESERVATION_HPP
