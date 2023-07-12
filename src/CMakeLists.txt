project(A++)

add_library(frontend FrontEnd.cpp FileHandlers.cpp)
add_library(helpers Logger.cpp)
add_library(lib VirtualMachine.cpp)

target_include_directories(frontend
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_include_directories(helpers
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_include_directories(lib
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

