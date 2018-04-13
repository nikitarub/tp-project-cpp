#include "word_vector.h"
#include <cassert>

WordVector::WordVector(const std::string &word) :
        word(word) {
}

WordVector WordVector::operator+(const WordVector &wordVector) {
    assert(vector.size() == wordVector.vector.size());

    WordVector result("");
    for (size_t i = 0; i < vector.size(); ++i) {
        result.vector[i] = vector[i] + wordVector.vector[i];
    }

    return result;
}

WordVector &WordVector::operator+=(const WordVector &wordVector) {
    assert(vector.size() == wordVector.vector.size());

    for (size_t i = 0; i < vector.size(); ++i) {
        vector[i] += wordVector.vector[i];
    }

    return *this;
}

WordVector::WordVector(const word_vector_t &vector) :
        vector(vector) {
}
