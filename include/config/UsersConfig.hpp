#pragma once
#include "nlohmann/json.hpp"
using json = nlohmann::json;
namespace config
{
    class UserConfig
    {
    public:
        static UserConfig &instance()
        {
            static UserConfig _instance;
            return _instance;
        }

        int getLastID() const;
        int getLastIDandIncrease();
        void intialLastID(int);

    private:
        int ID_track;
        UserConfig();
        UserConfig(const UserConfig &) = delete;
        UserConfig &operator=(const UserConfig &) = delete;
    };

}

namespace nlohmann
{
    template <>
    struct adl_serializer<config::UserConfig>
    {
        static void to_json(json &j, const config::UserConfig &user_config)
        {
            j = json{
                {"user-id", user_config.getLastID()},
            };
        }
    };

}