#pragma once
#include <filesystem>
namespace fs = std::filesystem;

class FileSystem
{
public:
    static bool exists(fs::path);
    static bool isEmpty(fs::path);
    static bool ifNotExistsCreate(fs::path);
    static bool isDir(fs::path);
    static bool isFile(fs::path);
};