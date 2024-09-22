package vm

import "core:fmt"

Instructions :: enum i64 {
        PUSH,
        ADD,
        MINUS
}

Operation :: union {
        Instructions,
        i64,
}

virtualMachine :: proc (program : [dynamic] Operation) -> bool {
        stack: [100]i64;
        stackPointer: i64 = 0;

        for programCounter: i64 = 0; programCounter < i64(len(program)) ; programCounter += 1 {
                currentInstruction : Instructions = program[programCounter].(Instructions);

                switch currentInstruction {
                case .PUSH:
                        stack[stackPointer] = program[programCounter + 1].(i64);
                        stackPointer += 1;
                        programCounter += 1;
                case .ADD:
                        right: i64 = stack[stackPointer - 1];
                        stackPointer -= 1;
                        left: i64 = stack[stackPointer - 1];
                        stackPointer -= 1;
                        stack[stackPointer] = left + right;
                        stackPointer += 1;
                case .MINUS:
                        right: i64 = stack[stackPointer - 1];
                        stackPointer -= 1;
                        left: i64 = stack[stackPointer - 1];
                        stackPointer -= 1;
                        stack[stackPointer] = left - right;
                        stackPointer += 1;
                }
        }

        fmt.println("stacktop:", stack[stackPointer - 1]);

        return true;
}
