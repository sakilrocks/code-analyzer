
#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

namespace Utils {
    std::string color(const std::string& text, const std::string& colorCode);
    bool fileExists(const std::string& path);
}


#endif