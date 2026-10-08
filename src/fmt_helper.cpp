#include <bstr/fmt_helper.hpp>
#include <bstr/format.hpp>
#include <bstr/error.hpp>
#include <string>
#include <vector>

std::string bstr::fmt_helper::format(
    std::string str, const std::vector<std::string>& str_args,
    size_t required_args
) {
    size_t cursor_index = 0;
    size_t arg_index = 0;
    size_t str_args_index = 0;
    std::string formatted_str = "";
    size_t find_index = str.find(target_symbol, cursor_index);
    
    while (find_index != std::string::npos) {

        if (str_args_index >= str_args.size()) {
            throw err::LessArgError(required_args, str_args.size());
        }
        
        formatted_str += str.substr(cursor_index, find_index - cursor_index);
        formatted_str += str_args[str_args_index++];
        
        cursor_index = find_index + target_symbol.size();
        find_index = str.find(target_symbol, cursor_index);
    }

    formatted_str += str.substr(cursor_index);

    return formatted_str;
}

size_t bstr::fmt_helper::count_word(
    const std::string& str, const std::string& word
) {
    size_t count = 0;
    std::string::size_type pos = 0;

    while ((pos = str.find(word, pos)) != std::string::npos) {
        ++count;
        pos += word.length();
    }

    return count;
}