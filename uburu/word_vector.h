#ifndef UBURU_WORD_VECTOR_H
#define UBURU_WORD_VECTOR_H

#include <string>
#include <vector>

typedef double word_vector_coord_t;
typedef std::vector<word_vector_coord_t > word_vector_t;

class WordVector {
    public:
        WordVector() = default;
        explicit WordVector(const std::string& word);
        explicit WordVector(const word_vector_t& vector);
        WordVector(const WordVector& wordVector) = default;
        WordVector(WordVector&& wordVector) noexcept = default;

        virtual ~WordVector() noexcept = default;

        WordVector& operator =(const WordVector& wordVector) = default;
        WordVector& operator =(WordVector&& wordVector) noexcept = default;

        WordVector operator +(const WordVector& wordVector);
        WordVector& operator +=(const WordVector& wordVector);

    private:
        std::string word;
        word_vector_t vector;
};

#endif //UBURU_WORD_VECTOR_H
