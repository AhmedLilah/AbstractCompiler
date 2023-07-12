#include "helpers/Logger.hpp"

#include <iostream>
#include <chrono>
#include <iomanip>

namespace logger {
auto printInfoCard() -> void {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    std::cout << 
        "A++ : A++ compiler\n"
        "Version : " << __DATE__ << "\n"
        "Developer : Ahmed S. Lilah\n"
        "Contacts : sabrylilah2325667@gmail.com\n";
        // "Process starting at : " << std::put_time(std::localtime(&time), "%A %d-%B-%Y") << "\n";
}

}

