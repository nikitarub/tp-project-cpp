#include "text_comparator.h"
#include "file_reader.h"

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
    FileReader firstReader(firstFile), secondReader(secondFile);
    // TODO
}

void TextComparator::CopyFrom(const TextComparator &textComparator) {
    // TODO
}

void TextComparator::MoveFrom(TextComparator &&textComparator) noexcept {
    // TODO
}
