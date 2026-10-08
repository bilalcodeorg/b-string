#include <bstr/std_str.hpp>
#include <string>

std::string std::to_string(const char ch) {
    std::string str(&ch);
    return str;
}

std::string std::to_string(const char* raw_str) {
    std::string str(raw_str);
    return str;
}

std::string std::to_string(const std::string& str) {
    return str;
}