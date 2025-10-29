
#ifndef ANALYZER_HPP
#define ANALYZER_HPP

#include <string>
#include <vector>
#include "parser.hpp"

class Analyzer {
public:
    static void analyze(const FileInfo& file, std::vector<VariableInfo>& vars);
    static void findTODOs(const FileInfo& file);
};


#endif