#include <iostream>
#include "text_comparator.h"

int main() {
    TextComparator tc;
    auto result = tc.Compare(std::string("file1.txt"),
        std::string("file2.txt"), 1, 1);

    return 0;
}