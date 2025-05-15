#include "infrastructures/FileSystem.hpp"
#include <iostream>

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

void FileSystem::ifNotExistsCreate(fs::path path)
{
    std::error_code ec;
    bool exists = false;
    try
    {
        exists = this->exists(path);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what();
    }

    if (!exists)
    {
        if (isFile(path))
        {
            path = path.parent_path();
        }
        fs::create_directory(path);
        std::cout << path.c_str() << " is created successfully :)";
    } // else nothting
}
