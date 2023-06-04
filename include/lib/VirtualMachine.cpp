#include "VirtualMachine.hpp"


[[nodiscard("you must check if the virtualMachine ran correctly or not.")]] 
auto virtualMachine (std::vector<Instructions> & program) noexcept -> bool { 
    std::array<Instructions, 100> stack; 
    size_t programCounter {}; 
    size_t stackPointer {};
    while (programCounter < program.size()) { 
        Instructions currentInstruction {static_cast<Instructions>(program[programCounter])};
        switch (currentInstruction) { 
            case PUSH:
                stack[stackPointer] = static_cast<Instructions>(program[programCounter+1]);
                stackPointer++;
                programCounter++;
                break;
            case ADD: { 
                int right = stack[stackPointer-1];
                stackPointer--;
                int left = stack[stackPointer-1];
                stackPointer--;
                stack[stackPointer] = static_cast<Instructions>(left + right);
                stackPointer++;
                break;
            }
            case MINUS: {
                int right = stack[stackPointer-1];
                stackPointer--;
                int left = stack[stackPointer-1];
                stackPointer--; 
                stack[stackPointer] = static_cast<Instructions>(left - right);
                stackPointer++;
                break;
            }
        } 
        programCounter++;
    } 
    std::print("stacktop: {}", static_cast<int>(stack[stackPointer-1]));
    return 0;
}
