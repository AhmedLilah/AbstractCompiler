package abstract

import "vm"

main :: proc() {
        program: [dynamic] vm.Operation = {
                .PUSH, 10,
                .PUSH, 20,
                .ADD,
                .PUSH, 5,
                .MINUS,
        }
        
        vm.virtualMachine(program)    
}
