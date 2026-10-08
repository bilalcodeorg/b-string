#pragma once
#include <string>
#include <vector>

namespace std {
    std::string to_string(const char* raw_str);
    std::string to_string(const std::string& str);
}

namespace bstr { namespace fmt_helper {

    std::string format(
        std::string str, const std::vector<std::string>& str_args
    );

    int count_word(const std::string& str, const std::string& word);

    // Defination
    template <typename... Args>
    void parse_args(
        std::vector<std::string>& str_args, std::string arg, Args... args
    ) {
        str_args.push_back(arg);
        parse_args(str_args, args...);
    }
    template <typename Arg, typename... Args>
    void parse_args(
        std::vector<std::string>& str_args, Arg arg, Args... args
    ) {
        str_args.push_back(std::to_string(arg));
        parse_args(str_args, args...);
    }

}}