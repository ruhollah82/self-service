#pragma once
#include "nlohmann/json.hpp"
using json = nlohmann::json;
namespace config
{
    class AdminConfig
    {
    public:
        static AdminConfig &instance()
        {
            static AdminConfig _instance;
            return _instance;
        }

        int getLastID() const;
        int getLastIDandIncrease();
        void intialLastID(int);
        void save();

    private:
        int ID_track;
        AdminConfig();
        AdminConfig(const AdminConfig &) = delete;
        AdminConfig &operator=(const AdminConfig &) = delete;
    };

}

namespace nlohmann
{
    template <>
    struct adl_serializer<config::AdminConfig>
    {
        static void to_json(json &j, const config::AdminConfig &admin_config)
        {
            j = json{
                {"admin-id", admin_config.getLastID()},
            };
        }

        static void from_json(const json &j, config::AdminConfig &admin_config)
        {
            admin_config.intialLastID(j.at("admin-id").get<int>());
        }
    };

}