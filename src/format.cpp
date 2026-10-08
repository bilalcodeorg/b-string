#include <bstr/format.hpp>
#include <string>
#include <vector>

std::string bstr::fmt_helper::format(
    std::string str, const std::vector<std::string>& str_args
) {
    size_t index = 0;
    size_t arg_index = 0;
    size_t str_values_index = 0;
    std::string formatted_str = "";
    
    size_t find_index = str.find(target_symbol, index);
    
    while (find_index >= 0) {
        
        formatted_str += str.substr(index, find_index);
        formatted_str += str_args[str_values_index++];
        
        find_index = str.find(target_symbol, index);
        index = find_index + 2;
    }

    return formatted_str;
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