#include <bstr/error.hpp>
#include <bstr/format.hpp>
#include <stdexcept>

bstr::err::LessArgError::LessArgError(
    size_t required_arg_len, size_t given_arg_len

) : runtime_error(format(LessArgErrorMsg, required_arg_len, given_arg_len)) { }