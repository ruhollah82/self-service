#pragma once
#include <filesystem>
namespace fs = std::filesystem;

class Student;
class FileSystem
{
public:
    static FileSystem &instance()
    {
        static FileSystem _instance;
        return _instance;
    }

    bool exists(fs::path);
    bool isEmpty(fs::path);
    void ifNotExistsCreate(fs::path);
    bool isDir(fs::path);
    bool isFile(fs::path);

private:
    // PATHES

    FileSystem() = default;
    FileSystem(const FileSystem &) = delete;
    FileSystem &operator=(const FileSystem &) = delete;
};