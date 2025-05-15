#include "config/UsersConfig.hpp"
#include "config/AppConfig.hpp"
#include <nlohmann/json.hpp>
#include <fstream>
using namespace std;
using json = nlohmann ::json;
int config::UserConfig::getLastID() const
{
    return this->ID_track;
}
int config::UserConfig::getLastIDandIncrease()
{
    return this->ID_track++;
}
void config::UserConfig::intialLastID(int id)
{
    this->ID_track = id;
}

config::UserConfig::UserConfig()
{
    ifstream file{config::AppConfig::instance().j_AppConfig, ios::in};
    json j = json::parse(file);
    this->intialLastID(j.at("user-id").get<int>());
}
