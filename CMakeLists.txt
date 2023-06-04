cmake_minimum_required(VERSION 3.10)
project(A++)


# specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add include directories
include_directories(include)

# add executable
add_executable(A++ ./src/main.cpp ./include/Helpers/Logger.cpp)
