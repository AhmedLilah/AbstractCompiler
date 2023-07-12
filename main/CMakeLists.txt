project(A++)

add_executable(A++ main.cpp)

target_link_libraries(main
        PRIVATE
        frontend
        helpers
        lib
)
