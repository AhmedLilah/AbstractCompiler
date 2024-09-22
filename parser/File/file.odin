
bool debugMode {};

std::vector<std::tuple<std::string, CLIArgs>> stringToCLIArgsVect {
        {"-i", CLIArgs::InputNetlistName}
}; 

auto openInputFile(std::string inputFileName) -> std::ifstream {
        try {
                std::ifstream inputFile(inputFileName);
                if (debugMode) std::cout << "openInputFile() finishing successfully\n";
                return inputFile;
        } catch (std::ios_base::failure& IOS) {
                std::cerr << "Error: std::ios_base::failure exception: " << IOS.what();
                std::terminate();
        }
}


auto convertInputFileToString(std::ifstream& inputFile) -> std::string {
        std::string inputString(std::istreambuf_iterator(inputFile), {});
        if (debugMode) std::cout << "convertInputFileToString() finishing successfully\n";
        return inputString;
}


auto getLinesFromString(std::string & inputString) -> std::vector<std::string> {
        auto splittedStringRange = inputString | std::ranges::views::split('\n');
        std::vector<std::string> linesVect;
        for (auto line : splittedStringRange) {
                linesVect.push_back(std::string(line.begin(), line.end()));
        }
        if (debugMode) std::cout << "getLinesFromString() finishing successfully\n";
        return linesVect;
}


auto createOutputFile(std::string& outputFileName) -> std::ofstream 
{
        try {
                std::ofstream outputFile(outputFileName);
                return outputFile;
        } catch (std::ios_base::failure& IOS) {
                std::cerr << "Error: std::ios_base::failure exception: " << IOS.what();
                // std::terminate();
                return {};
        }
}


auto writeToOutputFile(std::ofstream& outputFile, std::string& outputString) -> bool {
        if (outputFile << outputString) {
                outputFile.close();
                return true;
        }
        return false;
}


auto parseCommandlineArgs(int argc, char** argv) -> std::vector<std::pair<CLIArgs, std::string>> {
        if (debugMode) std::cout << "Entering parseCommandlineArgs()\n";
        std::vector<std::pair<CLIArgs, std::string>> argsDataPairVect;
        for (int i{1}; i < argc; i=i+2) {
                std::string arg {argv[i]};
                if (arg.find("--") or arg.find("-") == 0) {
                        std::pair<CLIArgs, std::string> tempPair { std::get<1>(stringToCLIArgsVect[0]), std::string(argv[i+1]) };
                        argsDataPairVect.push_back(tempPair);
                }
        }
        if (debugMode) std::cout << "parseCommandlineArgs() finishing successfully\n";
        return argsDataPairVect;
}


auto invokeFrontend(std::vector<std::pair<CLIArgs, std::string>> argsDataPairVect) -> std::vector<std::tuple<comp::CompilerOptions, std::string>> {
        auto getArgumentData = [&](CLIArgs arg) -> std::string {
                for (auto pair : argsDataPairVect) {
                        if (pair.first != arg)
                                continue;
                        if (pair.second.length() ==0)
                                continue;
                        return pair.second;
                }
                std::cerr << "argument no found.\n";
                // std::terminate();
                return {};
        };
        auto inputFile{ frontend::openInputFile(getArgumentData(CLIArgs::InputNetlistName))};
        auto inputString{ frontend::convertInputFileToString(inputFile) };
        auto stringLinesVect{ frontend::getLinesFromString(inputString)};
        return {{},{}};
}


auto formatOutput(std::vector<std::string> & outputsVect) -> std::string{
        std::string outputString;
        return outputString;
}


auto directOutput(std::string& outputString, CLIArgs arg) -> bool {
        // if (usedOptionsVect["--out"]) {
        //     if (argsVect["--out"].empty()) {
        //         throw std::invalid_argument("file name can't be and empty string");
        //     } else {
        //         std::string outputFileName = argsVect["--out"] + ".txt";
        //         std::ofstream outputFile{ createOutputFile(outputFileName) };
        //         writeToOutputFile(outputFile, outputString);
        //     }
        // } else {
        //     std::cout << outputString;
        // }
        return false;
}
