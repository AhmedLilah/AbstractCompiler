cmake_minimum_required(VERSION 3.10)
project(A++)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the rest of the directories
add_subdirectory(include)
add_subdirectory(src)

# adding the option to control whether to build the excutable or not.
option(BUILD_MAIN "Whether or not to build examples" ON)
if (BUILD_MAIN)
        message(STATUS "Building excutable...")
        add_subdirectory(main)
endif()
