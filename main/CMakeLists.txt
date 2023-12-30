project(A++)

add_executable(A++ A++.cpp)

target_link_libraries(A++ PRIVATE
        frontend helpers lib
)

# Set the linker search directories for the executable
target_link_directories(A++ PRIVATE "${CMAKE_BINARY_DIR}/src/Release")


# # Print the value of the INTERFACE_LINK_LIBRARIES property for each shared library target
# get_target_property(frontend_link_libraries frontend INTERFACE_LINK_LIBRARIES)
# message("frontend INTERFACE_LINK_LIBRARIES: ${frontend_link_libraries}")

# get_target_property(helpers_link_libraries helpers INTERFACE_LINK_LIBRARIES)
# message("helpers INTERFACE_LINK_LIBRARIES: ${helpers_link_libraries}")

# get_target_property(lib_link_libraries lib INTERFACE_LINK_LIBRARIES)
# message("lib INTERFACE_LINK_LIBRARIES: ${lib_link_libraries}")

# this is to make sure the A++ executable unts in visual studio as the startup project 
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT A++)
