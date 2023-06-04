#include "../include/Frontend/Frontend.hpp"
#include "../include/Helpers/Logger.hpp"
#include "../include/Utilities/CppLanguageInhancement.hpp"
#include <functional>

auto main(int argc, char ** argv) -> int {
    logger::printInfoCard();
    auto vecCLIArgsData = frontend::parseCommandlineArgs(argc, argv);
    frontend::invokeFrontend(vecCLIArgsData);
    return 0;
}
