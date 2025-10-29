
#include "parser.hpp"

#include <fstream>
#include <regex>
#include <iostream>

FileInfo Parser::readFile(const std::string& path) {
    FileInfo file;
    file.filename = path;
    std::ifstream in(path);
    std::string line;
    while (std::getline(in, line)) {
        file.lines.push_back(line);
    }
    return file;
}

std::vector<VariableInfo> Parser::extractVariables(const FileInfo& file) {
    std::vector<VariableInfo> vars;
    std::regex varPattern(R"(\b(?:int|float|double|char|bool|string)\s+(\w+)\s*(=|;))");
    for (size_t i = 0; i < file.lines.size(); ++i) {
        std::smatch match;
        if (std::regex_search(file.lines[i], match, varPattern)) {
            VariableInfo var{match[1], static_cast<int>(i + 1), false};
            vars.push_back(var);
        }
    }
    return vars;
}