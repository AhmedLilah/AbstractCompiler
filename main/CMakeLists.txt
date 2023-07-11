cmake_minimum_required(VERSION 3.10)
project(A++)

add_executable(main main.cpp)

target_link_libraries(main
        PRIVATE
        abstract_library
        )
