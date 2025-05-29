#ifndef ADMIN_HPP
#define ADMIN_HPP

#include "User.hpp"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Admin : public User
{
public:
    Admin();
    Admin(int id, string name, string lastName, string password);

    // Admin-specific methods
    void manageUsers();
    void manageReservations();
    void manageMeals();

    // Override print method
    void print() const override;
};

namespace nlohmann
{
    template <>
    struct adl_serializer<Admin>
    {
        static void to_json(json &j, const Admin &ad)
        {
            j = json{
                {"id", ad.getID()},
                {"name", ad.getName()},
                {"lastname", ad.getLastName()},
                {"hash", ad.getHashedPassword()},
            };
        }
        static void from_json(const json &j, Admin &ad)
        {
            ad.setID(j.at("id").get<int>());
            ad.setName(j.at("name").get<string>());
            ad.setLastName(j.at("lastname").get<string>());
            ad.setHashedPassword(j.at("hash").get<string>());
        }
    };
}

#endif // ADMIN_HPP