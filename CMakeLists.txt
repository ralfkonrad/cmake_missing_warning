cmake_minimum_required(VERSION 4.0)

# Target specific architectures for macOS and iOS, enable dual builds both for arm64 and amd64 architectures
# According to the documentation:
#   The value of this variable should be set prior to the first project() or enable_language() command
#   invocation because it may influence configuration of the toolchain and flags
if (APPLE AND NOT DEFINED CMAKE_OSX_ARCHITECTURES)
    set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64" CACHE STRING "Target architectures for Apple platforms" FORCE)
endif()

project(hello_world VERSION 0.0.1 LANGUAGES CXX)

set(RKE_BOOST_VERSION "1.90.0" CACHE STRING "Boost version we want to use to ensure compatibility")

# Keep behavior stable: silence warnings about newer Boost versions.
set(Boost_NO_WARN_NEW_VERSIONS ON)

# The FindBoost module is removed in CMake 3.30; prefer upstream BoostConfig.cmake.
# When CMP0167 is OLD, the CONFIG keyword is rejected, so fall back to module mode.
if (POLICY CMP0167)
    cmake_policy(GET CMP0167 _ql_mvn_cmp0167)
endif()

if (NOT DEFINED _ql_mvn_cmp0167 OR _ql_mvn_cmp0167 STREQUAL "NEW")
    find_package(Boost ${RKE_BOOST_VERSION} EXACT CONFIG REQUIRED)
else()
    find_package(Boost ${RKE_BOOST_VERSION} EXACT REQUIRED)
endif()

unset(_ql_mvn_cmp0167)

add_executable(hello_world main.cpp)
