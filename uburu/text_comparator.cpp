#include "text_comparator.h"

#include <vector>
#include <cassert>
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

std::vector<WordVector> get_sentnces(const std::string& fileName) {
    FileReader firstReader(fileName);

    std::string str;
    std::vector<WordVector> sentences;

    while (!(str = firstReader.ReadLine()).empty()) {
        auto indexes = IndexFileParser().ParseString(str);
        if (indexes.empty()) {
            break;
        }

        auto sVec = WordVector(WordVectorTable()[indexes[0]]);
        for (size_t i = 1; i < indexes.size(); ++i) {
            sVec += WordVectorTable()[indexes[i]];
        }

        sentences.push_back(sVec);
    }

    return sentences;
}

bool get_window(WordVector& window,
        const std::vector<WordVector>& sentences,
        size_t startIndex, size_t windowSize) {
    assert(!sentences.empty());

    auto winVec = WordVector(sentences[0]);
    for (size_t i = startIndex; i < std::min(startIndex +
            windowSize, sentences.size()); ++i) {
        winVec += sentences[i];
        return true;
    }

    return false;
}

similarity_coeff_t
TextComparator::Compare(const std::string &firstFile,
                        const std::string &secondFile,
                        size_t firstWindowSize,
                        size_t secondWindowSize) {
    auto firstTextSentences = get_sentnces(firstFile);
    auto secondTextSentences = get_sentnces(secondFile);

    std::vector<WordVector> firstTextWindows, secondTextWindows;

    WordVector sVec;
    size_t startIndex = 0;
    while (get_window(sVec, firstTextSentences, startIndex, firstWindowSize)) {
        firstTextWindows.push_back(sVec);
        startIndex += firstWindowSize;
    }

    startIndex = 0;
    while (get_window(sVec, secondTextSentences, startIndex, secondWindowSize)) {
        secondTextWindows.push_back(sVec);
        startIndex += secondWindowSize;
    }

    return 0.58;
}

void TextComparator::CopyFrom(const TextComparator &textComparator) {
    // TODO
}

void TextComparator::MoveFrom(TextComparator &&textComparator) noexcept {
    // TODO
}
