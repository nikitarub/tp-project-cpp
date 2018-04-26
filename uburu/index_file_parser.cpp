#include "index_file_parser.h"
#include <sstream>

std::vector<size_t> IndexFileParser::ParseString(const std::string &str) {
    std::vector<size_t> indexes;

    size_t index;
    std::istringstream strStream(str);
    while (strStream >> index) {
        indexes.push_back(index);
    }

    return indexes;
}