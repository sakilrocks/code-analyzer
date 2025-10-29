
#include "analyzer.hpp"
#include "utils.hpp"

#include <iostream>
#include <regex>

void Analyzer::analyze(const FileInfo& file, std::vector<VariableInfo>& vars) {
    for (size_t i = 0; i < file.lines.size(); ++i) {
        for (auto& var : vars) {
            if (file.lines[i].find(var.name) != std::string::npos && i + 1 != var.line) {
                var.used = true;
            }
        }
    }

    for (const auto& var : vars) {
        if (!var.used) {
            std::cout << Utils::color("[WARN] ", "\033[33m")
                      << file.filename << ":" << var.line
                      << " -> var: '" << var.name << "' declared but never used\n";
        }
    }
}

void Analyzer::findTODOs(const FileInfo& file) {
    std::regex todoPattern(R"(//.*(TODO|FIXME))");
    for (size_t i = 0; i < file.lines.size(); ++i) {
        if (std::regex_search(file.lines[i], todoPattern)) {
            std::cout << Utils::color("[NOTE] ", "\033[36m")
                      << file.filename << ":" << i + 1
                      << " -> found TODO/FIXME comment\n";
        }
    }
}