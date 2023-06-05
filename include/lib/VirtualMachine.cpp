#include "VirtualMachine.hpp"


[[nodiscard("you must check if the virtualMachine ran correctly or not.")]] 
auto virtualMachine (std::vector<int64_t> & program) noexcept -> bool { 
    std::array<int64_t, 100> stack; 
    int64_t programCounter {}; 
    int64_t stackPointer {};
    while (programCounter < program.size()) { 
        int64_t currentInstruction {program[programCounter]};
        switch (currentInstruction) { 
            case PUSH:
                stack[stackPointer] = program[programCounter+1];
                stackPointer++;
                programCounter++;
                break;
            case ADD: { 
                int64_t right = stack[stackPointer-1];
                stackPointer--;
                int64_t left = stack[stackPointer-1];
                stackPointer--;
                stack[stackPointer] = left + right;
                stackPointer++;
                break;
            }
            case MINUS: {
                int64_t right = stack[stackPointer-1];
                stackPointer--;
                int64_t left = stack[stackPointer-1];
                stackPointer--; 
                stack[stackPointer] = left - right;
                stackPointer++;
                break;
            }
        } 
        programCounter++;
    } 
    std::print("stacktop: {}", stack[stackPointer-1]);
    return 0;
}
