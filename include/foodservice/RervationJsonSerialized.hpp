#pragma once
#include "Reservation.hpp"
#include "roles/Student.hpp"
#include <nlohmann/json.hpp>
#include "foodservice/Meal.hpp"
#include "utils/Utilities.hpp"
#include "infrastructures/Storage.hpp"
#include "auth/SessionManager.hpp"
#include <exception>
using namespace std;
using json = nlohmann::json;

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
                {"student-id", reserve.getStudent().getID()},
                {"meal-id", reserve.getMeal().getMealID()},
                {"dininghall-id", reserve.getDiningHall().getHallID()}};
        }

        static void from_json(json &j, Reservation &reserve)
        {
            int student_id = j.at("stduent-id").get<int>();
            if (SessionManager::instace().currentStudent().getID() == student_id)
            {

                reserve.setStatus(j.at("status").get<RStatus>());
                reserve.setCreatedAt(j.at("created-at").get<time_t>());
                reserve.setReservationID(j.at("id").get<int>());
                reserve.setStudent(&SessionManager::instace().currentStudent());
                int meal_id = j.at("student-id").get<int>();
                int dhall_id = j.at("dininghall-id").get<int>();
                // TODO: should be in separated function
                for (int i = 0; i < Storage::allMeals.size(); i++)
                    if (Storage::allMeals[i].getMealID() == meal_id)
                        reserve.setMeal(Storage::allMeals[i]);
                    else
                        throw invalid_argument("Meal with id " + std::to_string(meal_id) + " is not available");

                for (int i = 0; i < Storage::allDiningHalls.size(); i++)
                    if (Storage::allDiningHalls[i].getHallID() == dhall_id)
                        reserve.setDiningHall(Storage::allDiningHalls[i]);
                    else
                        throw invalid_argument("Dhall with id " + std::to_string(dhall_id) + " is not available");
            }
        }
    };
};
