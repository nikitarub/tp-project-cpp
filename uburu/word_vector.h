#ifndef UBURU_WORD_VECTOR_H
#define UBURU_WORD_VECTOR_H

#include <string>
#include <vector>

typedef double word_vector_coord_t;

class WordVector {
    public:
        WordVector() = delete;
        explicit WordVector(const std::string& word);

        virtual ~WordVector() noexcept;

    private:
        std::string word;
        std::vector<word_vector_coord_t> vector;
};

#endif //UBURU_WORD_VECTOR_H
