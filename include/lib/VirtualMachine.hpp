#pragma one 
#include <stdint.h>
#include <vector>
#include <print>
#include <array>

enum Instructions {
    PUSH,
    ADD,
    MINUS,
};

[[nodiscard("you must check if the virtualMachine ran correctly or not.")]] 
auto virtualMachine (std::vector<int64_t> & program) noexcept -> bool; 
