#ifndef UBURU_TEXT_COMPARATOR_H
#define UBURU_TEXT_COMPARATOR_H

#include <string>

typedef double similarity_coeff_t;

class TextComparator {
    public:
        TextComparator() = default;
        TextComparator(const TextComparator& textComparator);
        TextComparator(TextComparator&& textComparator) noexcept;

        virtual ~TextComparator() noexcept = default;

        TextComparator& operator =(const TextComparator& textComparator);
        TextComparator& operator =(TextComparator&& textComparator) noexcept;

        similarity_coeff_t Compare(const std::string& firstFile, const std::string& secondFile,
                                   size_t firstWindowSize, size_t secondWindowSize);

    private:
        void CopyFrom(const TextComparator& textComparator);
        void MoveFrom(TextComparator&& textComparator) noexcept;
};

#endif //UBURU_TEXT_COMPARATOR_H
