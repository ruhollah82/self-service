#include "config/AdminConfig.hpp"
#include "config/ConfigPaths.hpp"
#include "infrastructures/FileSystem.hpp"
#include <nlohmann/json.hpp>
#include <fstream>
using namespace std;
using json = nlohmann ::json;
int config::AdminConfig::getLastID() const
{
    return this->ID_track;
}
int config::AdminConfig::getLastIDandIncrease()
{
    return this->ID_track++;
}
void config::AdminConfig::intialLastID(int id)
{
    this->ID_track = id;
}

config::AdminConfig::AdminConfig()
{
    auto file = config::ConfigPaths::instance().j_admin_config;
    if (FileSystem::exists(file))
    {
        ifstream reader(file);
        json j = json::parse(reader);
        this->intialLastID(j.at("user-id").get<int>());
        reader.close();
    }
    else
    {
        throw runtime_error("admin_config file doesn't exists :(");
    }
}

void config::AdminConfig::save()
{
    auto file = config::ConfigPaths::instance().j_admin_config;
    FileSystem::ifNotExistsCreate(file);
    ofstream writer(file);
    json j = *this;
    writer << j;
    writer.close();
}