#ifndef MEAL_HPP
#define MEAL_HPP
#include "utils/Utilities.hpp"
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
using namespace std;
using json = nlohmann::json;

class Meal
{
public:
    Meal();
    Meal(int, string, float, vector<string>);
    ReserveDay getReserveDay() const { return _reserveDay; }
    // Getters
    int getMealID() const { return _mealID; }
    string getName() const { return _name; }
    float getPrice() const { return _price; }
    bool isActive() const { return _isActive; }
    MealType getMealType() const { return _mealType; }
    vector<string> getSideItems() const { return _sideItems; }

    // Setters
    void setMealID(int mealID) { _mealID = mealID; }
    void setName(string name) { _name = name; }
    void setPrice(float price) { _price = price; }
    void setMealType(MealType mealType) { _mealType = mealType; }
    void setSideItems(vector<string> sideItems) { _sideItems = sideItems; }
    void setResesrveDay(ReserveDay reserveDay) { _reserveDay = reserveDay; }

    // Activation and DeActivation
    void activate() { _isActive = true; }
    void deactivate() { _isActive = false; }

    // Other Methods
    void print();
    void input();
    void addSideItem(string);
    void addPrice(float);

private:
    int _mealID;
    string _name;
    float _price;
    bool _isActive;
    MealType _mealType;
    ReserveDay _reserveDay;
    vector<string> _sideItems;
};

namespace nlohmann
{
    template <>
    struct adl_serializer<Meal>
    {
        static void to_json(json &j, const Meal &meal)
        {
            j = json{
                {"mealID", meal.getMealID()},
                {"name", meal.getName()},
                {"price", meal.getPrice()},
                {"isActive", meal.isActive()},
                {"mealType", meal.getMealType()},
                {"sideItems", meal.getSideItems()},
                {"reserve-day", meal.getReserveDay()},
            };
        }

        static void from_json(const json &j, Meal &meal)
        {
            meal.setMealID(j.at("mealID").get<int>());
            meal.setName(j.at("name").get<string>());
            meal.setPrice(j.at("price").get<float>());
            meal.setMealType(j.at("mealType").get<MealType>());
            meal.setSideItems(j.at("sideItems").get<vector<string>>());
            meal.setResesrveDay(j.at("reserve-day").get<ReserveDay>());
            if (j.at("isActive").get<bool>())
                meal.activate();
            else
                meal.deactivate();
        }
    };
};

#endif