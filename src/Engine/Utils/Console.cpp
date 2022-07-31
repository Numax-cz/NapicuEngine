

#include "Console.h"
namespace Napicu{

    void Console::Log(std::string msg) {
        //std::cout << "\033[31m" << "Error!" << msg << "\033[0m"  << std::endl;
        std::cout << "[NAPICUENGINE]" << " - " << msg << std::endl;
    }

    void Console::Info(std::string info){
        std::cout << "[NAPICUENGINE - Info]" << " - " << info << std::endl;
    }

    void Console::Error(std::string error) {
        std::cout << "[NAPICUENGINE - Error]" << " - " << error << std::endl;
    }
}