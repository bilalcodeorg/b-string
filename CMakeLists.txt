# CMakeList.txt : CMake project for wlan-pc-bcode, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.10)

project (BString VERSION 1.0 LANGUAGES CXX)

# Add library
add_library(
	BString STATIC
    src/fmt_helper.cpp
    src/std_str.cpp
)
add_library(bstr::bstr ALIAS BString)
target_include_directories(BString
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
set_target_properties(BString PROPERTIES
    OUTPUT_NAME "b_string"
    PREFIX ""
)

# Cmake version
set_target_properties(
    BString
    PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
)