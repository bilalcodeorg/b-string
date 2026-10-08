#include <bstr/format.hpp>
#include <string>
#include <vector>

template <typename... Args>
std::string bstr::format(std::string str, Args... args) {
    size_t index = 0;
    size_t arg_index = 0;
    size_t str_values_index = 0;
    std::string formatted_str = "";
    std::vector<std::string> str_args;

    // Reserving space for array
    str_args.reserve(fmt_helper::count_word(str, "{}"));

    // Parsing variable arguments
    fmt_helper::parse_args(str_args, args...);
    
    size_t find_index = str.find("{}", index);
    
    while (find_index >= 0) {
        
        formatted_str += str.substr(index, find_index);
        formatted_str += str_args[str_values_index++];
        
        find_index = str.find("{}", index);
        index = find_index + 2;
    }

    return formatted_str;
}

template <typename Arg, typename... Args>
void bstr::fmt_helper::parse_args(
    std::vector<std::string>& str_args, Arg arg, Args... args
){
    str_args.push_back(std::to_string(arg));
    parse_args(str_args, args...);
}

int bstr::fmt_helper::count_word(
    const std::string& str, const std::string& word
) {
    int count = 0;
    std::string::size_type pos = 0;

    while ((pos = str.find(word, pos)) != std::string::npos)
    {
        ++count;
        pos += word.length();
    }

    return count;
}