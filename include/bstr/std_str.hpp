#pragma once
#include <string>

namespace std {
    std::string to_string(const char ch);
    std::string to_string(const char* raw_str);
    std::string to_string(const std::string& str);
}