cmake_minimum_required(VERSION 3.26)
project(A++)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS ON)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_EXTENSIONS ON)

# add the rest of the directories
add_subdirectory(include)
add_subdirectory(src)
# add_subdirectory(main)

# adding the option to control whether to build the excutable or not.
option(BUILD_MAIN "Whether or not to build examples" ON)
if (BUILD_MAIN)
        message(STATUS "Building excutable...")
        add_subdirectory(main)
endif()

if(MSVC)
    add_compile_options(/std:c17)
endif()
