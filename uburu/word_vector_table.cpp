#include "word_vector_table.h"

const WordVector &WordVectorTable::operator[](size_t index) const {
    // TODO
}

WordVector WordVectorTable::operator [](size_t index) {
    WordVector vector(dictHandler.getVecbyId(index));
    return vector;
}
