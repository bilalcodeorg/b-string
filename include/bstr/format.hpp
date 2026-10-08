#pragma once
#include <string>
#include <vector>

namespace bstr {
    template <typename... Args>
    const std::string format(std::string first, Args... values);
}

namespace bstr::fmt_helper {
    template <typename Arg, typename... Args>
    void parse_args(
        std::vector<std::string>& str_arr, Arg value, Args... values
    );

    int count_word(const std::string& str, const std::string& word);
}