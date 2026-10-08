#pragma once
#include <bstr/std_str.hpp>
#include <string>
#include <vector>

namespace bstr { namespace fmt_helper {

    std::string format(
        std::string str, const std::vector<std::string>& str_args,
        size_t required_args
    );

    size_t count_word(const std::string& str, const std::string& word);

    // Base case
    inline void parse_args(std::vector<std::string>& str_args) { }

    // Recursive case
    template <typename Arg, typename... Args>
    void parse_args(
        std::vector<std::string>& str_args, Arg arg, Args... args
    ) {
        str_args.push_back(std::to_string(arg));
        parse_args(str_args, args...);
    }
}}