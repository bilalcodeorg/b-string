#pragma once

#include <stdexcept>
#include <string>

namespace bstr { namespace err {

const std::string LessArgErrorMsg =
    "LessArgError: format string requires {} argument(s), but only {} given";
    
class LessArgError : public std::runtime_error {
private:
public:
    LessArgError(size_t required_arg_len, size_t given_arg_len);
};
    
}}