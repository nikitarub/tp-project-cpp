#include "text_comparator.h"

#include <vector>
#include "file_reader.h"
#include "word_vector_table.h"
#include "index_file_parser.h"

TextComparator::TextComparator(const TextComparator &textComparator) {
    CopyFrom(textComparator);
}

TextComparator::TextComparator(TextComparator &&textComparator) noexcept {
    MoveFrom(std::move(textComparator));
}

TextComparator &TextComparator::operator=(const TextComparator &textComparator) {
    CopyFrom(textComparator);
    return *this;
}

TextComparator &TextComparator::operator=(TextComparator &&textComparator) noexcept {
    MoveFrom(std::move(textComparator));
    return *this;
}

similarity_coeff_t
TextComparator::Compare(const std::string &firstFile,
                        const std::string &secondFile,
                        size_t firstWindowSize,
                        size_t secondWindowSize) {
    FileReader firstReader(firstFile);

    std::string str;
    while (!(str = firstReader.ReadLine()).empty()) {
        auto indexes = IndexFileParser().ParseString(str);
        if (indexes.empty()) {
            break;
        }

        auto sVec = WordVector(WordVectorTable()[indexes[0]]);
        for (size_t i = 1; i < indexes.size(); ++i) {
            sVec += WordVectorTable()[indexes[i]];
        }

    }
}

void TextComparator::CopyFrom(const TextComparator &textComparator) {
    // TODO
}

void TextComparator::MoveFrom(TextComparator &&textComparator) noexcept {
    // TODO
}
