#pragma once
#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <map>
#include <unordered_map>
#include <vector>
#include <array>
#include <exception>
#include <stdexcept>
#include <utility>
#include <variant>
#include <queue>
#include <functional>
#include <execution>
#include <string_view>
#include <chrono>
#include <filesystem>
#include <ranges>
#include "../lib/Token.hpp"
#include "../lib/Compiler.hpp"
#include "../Utilities/CppLanguageInhancement.hpp"

namespace frontend {
enum class CLIArgs {
    InputNetlistName
};

// file support functions
auto openInputFile(std::string ) -> std::ifstream;
auto convertInputFileToString(std::ifstream &) -> std::string;
auto getLinesFromString(std::string &) -> std::vector<std::string>;
auto createOutputFile(std::string &) -> std::ofstream;
auto writeToOutputFile(std::ofstream &, std::string &) -> bool;

// main program flow functions
auto parseCommandlineArgs(int argc, char** argv) -> std::vector<std::pair<CLIArgs, std::string>>;
auto invokeFrontend(std::vector<std::pair<CLIArgs, std::string>> argsDataPairVect) -> std::vector<std::tuple<comp::CompilerOptions, std::string>>; 
auto formatOutput(std::vector<std::string> &) -> std::string;
auto directOutput(std::string &, CLIArgs arg) -> bool;
}
