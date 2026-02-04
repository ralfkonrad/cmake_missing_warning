cmake_minimum_required(VERSION 4.0)

project(cmake_missing_warning VERSION 0.0.1 LANGUAGES CXX)

if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
endif ()
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS FALSE)

set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

if (MSVC)
    add_compile_options(-W4)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(Boost 1.90.0 EXACT CONFIG REQUIRED)

add_executable(cmake_missing_warning main.cpp)
target_include_directories(cmake_missing_warning SYSTEM PUBLIC ${Boost_INCLUDE_DIRS})
