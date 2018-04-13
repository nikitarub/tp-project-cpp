#ifndef UBURU_INDEX_FILE_PARSER_H
#define UBURU_INDEX_FILE_PARSER_H

#include <string>
#include <vector>
#include "word_vector.h"

class IndexFileParser {
    public:
        IndexFileParser() = default;
        IndexFileParser(const IndexFileParser &parser) = default;
        IndexFileParser(IndexFileParser&& parser) noexcept = default;

        virtual ~IndexFileParser() noexcept = default;

        std::vector<size_t> ParseString(const std::string& str);
};

#endif //UBURU_INDEX_FILE_PARSER_H
