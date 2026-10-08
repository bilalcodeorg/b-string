#include <bstr/fmt_helper.hpp>
#include <string>

std::string to_string(const char* raw_str) {
    std::string str(raw_str);
    return raw_str;
}

std::string to_string(const std::string& str) {
    return str;
}