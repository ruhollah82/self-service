#pragma once
#include "infrastructures/FileSystem.hpp"
#include "config/ConfigPaths.hpp"
#include <vector>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
using namespace std;
namespace fs = std::filesystem;
using json = nlohmann::json;

class Meal;
class DinningHall;
class Reservation;
namespace filling
{
    template <typename T>
    class FoodService
    {
    public:
        static vector<T> giveAll();
        static bool save(vector<T>);
        static int getLastID();

    private:
        static fs::path giveFile();
        static bool initialIDFile();
    };
    template <typename T>
    vector<T> FoodService<T>::giveAll()
    {
        auto file = giveFile();
        if (FileSystem::ifNotExistsCreate(file))
        {
            std::cout << file << " is created successfuly :)" << endl;
        }
        fstream reader(file, ios::in);
        json jfile = json::parse(reader);
        return jfile.get<vector<T>>();
    }
    template <typename T>
    bool FoodService<T>::save(vector<T> list)
    {
        auto file = giveFile();
        fstream writer(file, ios::out);
        if (!writer.is_open())
            return false;
        try
        {
            json j;
            j = list;
            writer << j;
            writer.close();
            return true;
        }
        catch (...)
        {
            return false;
        }
    }

    template <>
    int FoodService<Meal>::getLastID();
    template <>
    int FoodService<DinningHall>::getLastID();
    template <typename T>
    bool FoodService<T>::initialIDFile()
    {
        auto file = config::ConfigPaths::instance().j_foodservice_ids;
        if (FileSystem::ifNotExistsCreate(file))
        {
            ofstream writer(file);
            if (!writer.is_open())
                return false;
            try
            {
                json j = {
                    {"meal-id", -1},
                    {"d-id", -1},
                };
                writer << j;
                writer.close();
                return true;
            }
            catch (...)
            {

                return false;
            }
        }
        else
        {
            return false;
        }
    }
}