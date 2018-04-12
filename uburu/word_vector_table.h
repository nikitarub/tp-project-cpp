#ifndef UBURU_WORD_VECTOR_TABLE_H
#define UBURU_WORD_VECTOR_TABLE_H

#include "word_vector.h"

class WordVectorTable {
    public:
        WordVectorTable();

        virtual ~WordVectorTable() noexcept;

        const WordVector& operator [](size_t index) const;
        WordVector& operator [](size_t index);

    private:

};

#endif //UBURU_WORD_VECTOR_TABLE_H
