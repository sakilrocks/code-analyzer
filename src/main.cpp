
#include "parser.hpp"
#include "analyzer.hpp"
#include "utils.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "usage: ./codeanalyzer <file.cpp>\n";
        return 1;
    }

    std::string path = argv[1];
    if (!Utils::fileExists(path)) {
        std::cerr << "error: file not found.\n";
        return 1;
    }

    FileInfo file = Parser::readFile(path);
    std::vector<VariableInfo> vars = Parser::extractVariables(file);

    std::cout << Utils::color("[INFO] ", "\033[32m")
              << "analyzing " << path << "...\n";

    Analyzer::analyze(file, vars);
    Analyzer::findTODOs(file);

    std::cout << Utils::color("[DONE] ", "\033[32m")
              << "analysis complete.\n";
}