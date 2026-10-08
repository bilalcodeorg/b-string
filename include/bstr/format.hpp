#pragma once
#include <string>
#include <vector>

namespace bstr {
    template <typename... Args>
    std::string format(std::string first, Args... args);
    

// C++11 support
// str::fmt_helper
namespace fmt_helper {

    template <typename Arg, typename... Args>
    void parse_args(
        std::vector<std::string>& str_args, Arg arg, Args... args
    );

    int count_word(const std::string& str, const std::string& word);

} // str::fmt_helper
}