cmake_minimum_required(VERSION 3.10)
project(A++)

add_library(abstract_library FileHandlers.cpp FrontEnd.cpp Logger.cpp VirtualMachine.cpp)

target_include_directories(abstract_library
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)
