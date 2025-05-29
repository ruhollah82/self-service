#ifndef DININGHALL_HPP
#define DININGHALL_HPP
#include <nlohmann/json.hpp>
#include <string>

using namespace std;
using json = nlohmann::json;

class DinningHall
{
public:
    DinningHall();
    DinningHall(int, string, string, int);

    // Getters
    int getHallID() const { return _hallID; }
    string getName() const { return _name; }
    string getAddress() const { return _address; }
    int getCapacity() const { return _capacity; }

    // Setters
    void setHallID(int hallID) { _hallID = hallID; }
    void setName(string name) { _name = name; }
    void setAddress(string address) { _address = address; }
    void setCapacity(int capacity) { _capacity = capacity; }

    // Other Methods:
    void print();
    void input();

private:
    int _hallID;
    string _name;
    string _address;
    int _capacity;
};

namespace nlohmann
{
    template <>
    struct adl_serializer<DinningHall>
    {

        static void from_json(const json &j, DinningHall &_dinningHall)
        {
            _dinningHall.setAddress(j.at("address").get<string>());
            _dinningHall.setCapacity(j.at("capacity").get<int>());
            _dinningHall.setHallID(j.at("id").get<int>());
            _dinningHall.setName(j.at("name").get<string>());
        }

        static void to_json(json &j, const DinningHall &_dinningHall)
        {
            j = json{
                {"id", _dinningHall.getHallID()},
                {"address", _dinningHall.getAddress()},
                {"name", _dinningHall.getName()},
                {"capacity", _dinningHall.getCapacity()},
            };
        }
    };
}

#endif // DININGHALL_HPP
