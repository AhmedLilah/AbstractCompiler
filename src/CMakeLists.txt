project(A++)

add_library(frontend SHARED FrontEnd.cpp FileHandlers.cpp)
add_library(helpers SHARED Logger.cpp)
add_library(lib SHARED VirtualMachine.cpp)

target_include_directories(frontend
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

set_target_properties(frontend PROPERTIES
    WINDOWS_EXPORT_ALL_SYMBOLS TRUE
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/src"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/src"
)

target_include_directories(helpers
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

set_target_properties(helpers PROPERTIES
    WINDOWS_EXPORT_ALL_SYMBOLS TRUE
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/src"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/src"
)

target_include_directories(lib
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

set_target_properties(lib PROPERTIES
    WINDOWS_EXPORT_ALL_SYMBOLS TRUE
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/src"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/src"
)

# Set the output directories for the shared library
# set_target_properties(frontend PROPERTIES
    # RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/src"
    # LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/src"
# )

# # Set the output directories for the shared library
# set_target_properties(helpers PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/src"
#     LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/src"
# )

# # Set the output directories for the shared library
# set_target_properties(lib PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/src"
#     LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/src"
# )

