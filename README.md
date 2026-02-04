# `cmake` does not treat `Boost` as a system library on github runner `macos-15-intel`

This small example sets up a `cmake` `c++` project include the `Boost` package
```cmake
find_package(Boost 1.90.0 EXACT CONFIG REQUIRED)
```
and treats the `${Boost_INCLUDE_DIRS}` as
```cmake
target_include_directories(cmake_missing_warning SYSTEM PUBLIC ${Boost_INCLUDE_DIRS})
```
The expectation would be that warnings emitted from `Boost` get suppressed.

Therefore, [`main.cpp`](./main.cpp) calls the constructor 
```cpp
boost::multi_array<double, 3> d(boost::extents[2][2][2]);
```
which contains deprecated "stuff".

The suppression of the deprecation warning works fine on all GitHub runners
except for `macos-15-intel` 
in the workflow [`build.yml`](./.github/workflows/build.yml).

The reason is obvious: while all other builds contain flags similar to 
`-isystem /opt/homebrew/include`, the `macos-15-intel` doesn't:

```
[1/2] /usr/bin/c++   -O3 -DNDEBUG -Werror -MD -MT CMakeFiles/main.dir/main.cpp.o -MF CMakeFiles/main.dir/main.cpp.o.d -o CMakeFiles/main.dir/main.cpp.o -c /Users/runner/work/cmake_missing_warning/cmake_missing_warning/main.cpp
```