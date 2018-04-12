#include <iostream>
#include "DictHandler.hpp"


int main(int argc, const char * argv[]) {
    DictHandler dict;
    std::ifstream file;
    file.open("/data/dict.txt");
    dict.fit(file);

    std::cout << dict.getId("а") << std::endl;
    
    std::vector<double> vec;
    vec =dict.getVecbyId(1);
    
    for (int i = 0; i < vec.size(); i++) {
        std::cout << dict.getVecbyId(1)[i] << " ";
    }
    
    
    return 0;
}

