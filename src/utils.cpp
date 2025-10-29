
#include "utils.hpp"

#include <fstream>

namespace Utils {
    std::string color(const std::string& text, const std::string& colorCode) {
        return colorCode + text + "\033[0m";
    }

    bool fileExists(const std::string& path) {
        std::ifstream f(path);
        return f.good();
    }
}