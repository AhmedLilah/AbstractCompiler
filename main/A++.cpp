#include "frontend/Frontend.hpp"
#include "helpers/Logger.hpp"
#include "lib/VirtualMachine.hpp"
#include "util/CppLanguageInhancement.hpp"

// #include <functional>
// #include <stack>
// #include <vector>
// #include <print>


auto main(int argc, char ** argv) -> int {
    logger::printInfoCard();
    auto vecCLIArgsData = frontend::parseCommandlineArgs(argc, argv);
    frontend::invokeFrontend(vecCLIArgsData);

    std::vector<int64_t> program{PUSH, static_cast<Instructions>(3), PUSH, static_cast<Instructions>(4), ADD, PUSH, static_cast<Instructions>(5), MINUS};
    auto result = virtualMachine(program);
    return 0;
}
