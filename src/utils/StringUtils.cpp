#include "utils/StringUtils.hpp"
#include <string>

using namespace std;

string string_utils::lstrip(const string &s, char char_to_strip)
{
    size_t first = s.find_first_not_of(char_to_strip);
    if (string::npos == first)
    {
        return "";
    }
    return s.substr(first);
}

string string_utils::rstrip(const string &s, char char_to_strip)
{
    size_t last = s.find_last_not_of(char_to_strip);
    if (string::npos == last)
    {
        return "";
    }
    return s.substr(0, last + 1);
}

string string_utils::strip(const string &s, char char_to_strip)
{
    size_t first = s.find_first_not_of(char_to_strip);
    if (string::npos == first)
    {
        return ""; // String contains only char_to_strip or is empty
    }
    size_t last = s.find_last_not_of(char_to_strip);
    return s.substr(first, (last - first + 1));
}