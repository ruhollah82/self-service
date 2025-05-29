#include "infrastructures/FileSystem.hpp"
#include "config/ConfigPaths.hpp"
#include "foodservice/Filling.hpp"
#include "foodservice/Meal.hpp"
#include "foodservice/DiningHall.hpp"
#include "foodservice/ReservationJsonSerialized.hpp"
#include <vector>
#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace filling;
using namespace std;
namespace fs = std::filesystem;

template <>
fs::path FoodService<Meal>::giveFile()
{
    return config::ConfigPaths::instance().j_meals;
}
template <>
fs::path FoodService<DinningHall>::giveFile()
{
    return config::ConfigPaths::instance().j_dining_halls;
}
template <>
fs::path FoodService<Reservation>::giveFile()
{
    return config::ConfigPaths::instance().j_reservations();
}

template <>
int FoodService<Meal>::getLastID()
{
    auto file = config::ConfigPaths::instance().j_foodservice_ids;
    if (FileSystem::exists(file))
    {
        ifstream reader(file);
        json j = json::parse(reader);
        reader.close();
        return j.at("meal-id").get<int>();
    }

    if (!initialIDFile())
    {
        throw runtime_error("something went wrong when initilizing the file :(");
    }
    return -1;
}
template <>
int FoodService<DinningHall>::getLastID()
{
    auto file = config::ConfigPaths::instance().j_foodservice_ids;
    if (FileSystem::exists(file))
    {
        ifstream reader(file);
        json j = json::parse(reader);
        reader.close();
        return j.at("d-id").get<int>();
    }
    if (!initialIDFile())
    {
        throw runtime_error("something went wrong when initilizing the file :(");
    }

    return -1;
}

template <>
bool FoodService<Meal>::updateLastID(int id)
{
    auto file = config::ConfigPaths::instance().j_foodservice_ids;
    bool status = false;
    if (!FileSystem::exists(file))
    {
        if (initialIDFile())
        {
            status = true;
        }
        else
            status = false;
    }
    else
        status = true;
    if (status)
    {
        try
        {
            ifstream reader(file);
            json j = json::parse(reader);
            reader.close();
            ofstream writer(file);
            j["meal-id"] = id;
            // cout << j.dump(5) << endl;
            writer << j;
            writer.close();
            return true;
        }
        catch (exception &e)
        {
            cerr << e.what() << "\nhappend during updating the meal Last ID :(\n";
            return false;
        }
    }
    else
        return false;
}

template <>
bool FoodService<DinningHall>::updateLastID(int id)
{
    auto file = config::ConfigPaths::instance().j_foodservice_ids;
    bool status = false;
    if (!FileSystem::exists(file))
    {
        if (initialIDFile())
        {
            status = true;
        }
        else
            status = false;
    }
    else
        status = true;
    if (status)
    {
        try
        {
            fstream writer(file, ios::in | ios::out);
            json j = json::parse(writer);
            j["d-id"] = id;
            writer << id;
            writer.close();
            return true;
        }
        catch (exception &e)
        {
            cerr << e.what() << "\nhappend during updating the DinningHall Last ID :(\n";
            return false;
        }
    }
    else
        return false;
}