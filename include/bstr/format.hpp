#pragma once
#include <bstr/fmt_helper.hpp>
#include <string>
#include <vector>

namespace bstr {
    const std::string target_symbol = "{}";

    // Defination
    template <typename... Args>
    std::string format(std::string str, Args... args) {

        std::vector<std::string> str_args;

        // Reserving space for array
        str_args.reserve(fmt_helper::count_word(str, target_symbol));
        
        // Parsing variable arguments
        fmt_helper::parse_args(str_args, args...);

        return fmt_helper::format(str, str_args);
    }
}