#include "infrastructures/FileSystem.hpp"
#include <iostream>
#include <fstream>
using namespace std;

bool FileSystem::exists(fs::path path)
{
    std::error_code ec;

    bool existance = fs::exists(path, ec);
    if (ec)
    {
        throw std::runtime_error("Somthing went wrong while Checking Existance of " + path.string() + " ERROR MSG: " + ec.message());
    }
    else
    {
        return (existance) ? true : false;
    }
}
bool FileSystem::isDir(fs::path path)
{
    std::error_code ec;
    bool is_dir = fs::is_directory(path, ec);
    if (ec)
        throw std::invalid_argument("Error checking " + path.string() + " is a dir or not?");
    else
        return is_dir;
}
bool FileSystem::isFile(fs::path path)
{
    std::error_code ec;
    bool is_file = fs::is_regular_file(path, ec);
    if (ec)
        throw std::invalid_argument("Error checking " + path.string() + " is a regular file or not?");
    else
        return is_file;
}
bool FileSystem::isEmpty(fs::path path)
{
    std::error_code ec;
    bool is_empty = fs::is_empty(path, ec);

    if (ec)
    {
        std::cerr << "Error: checking if " << path << "is empty!" << "info: " << ec.message() << "\n";
        throw std::invalid_argument("SOMETHING WENT WRONG!");
    }
    else
    {
        return (is_empty) ? true : false;
    }
}

bool FileSystem::ifNotExistsCreate(fs::path path)
{
    std::error_code ec;
    bool exists = false;
    try
    {
        exists = FileSystem::exists(path);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what();
        return false;
    }

    if (!exists)
    {
        bool file = false;
        fs::path pPath;
        string suffix = ".json";
        if (path.string().substr(path.string().size() - suffix.size(), suffix.size()) == suffix)
        {
            file = true;
            pPath = path.parent_path();
            if (!FileSystem::exists(pPath))
                fs::create_directories(pPath);
        }
        if (file && !FileSystem::exists(path))
        {
            ofstream writer(path);
            writer.close();
            return true;
        }
    } // else nothting
    return false;
}

bool FileSystem::copy_file(fs::path from, fs::path to)
{
    if (exists(from))
    {
        error_code ec;
        fs::copy_file(from, to, ec);
        if (ec)
        {
            cerr << ec.message() << endl
                 << "Got Error while Trying to copy '" << from << "' to '" << to << "' :(\n";
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        cerr << "'" << from << "' does't exists :(" << endl;
        return false;
    }
}