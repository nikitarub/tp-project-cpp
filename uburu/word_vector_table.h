#ifndef UBURU_WORD_VECTOR_TABLE_H
#define UBURU_WORD_VECTOR_TABLE_H

#include "word_vector.h"
#include "DictHandler.hpp"

class WordVectorTable {
    public:
        WordVectorTable() = default;

        virtual ~WordVectorTable() noexcept = default;

        const WordVector& operator [](size_t index) const;
        WordVector operator [](size_t index);

    private:
        DictHandler dictHandler;
};

#endif //UBURU_WORD_VECTOR_TABLE_H
