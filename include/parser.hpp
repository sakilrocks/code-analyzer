
#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>

struct VariableInfo {
    std::string name;
    int line;
    bool used = false;
};

struct FileInfo {
    std::string filename;
    std::vector<std::string> lines;
};

class Parser {
public:
    static FileInfo readFile(const std::string& path);
    static std::vector<VariableInfo> extractVariables(const FileInfo& file);
};


#endif 