//
//  dataStructs.hpp
//  project_cpp_xcode
//
//  Created by Nikita on 11.04.18.
//  Copyright © 2018 RIT. All rights reserved.
//

#ifndef dataStructs_hpp
#define dataStructs_hpp

#include <stdio.h>
#include <vector>
#include <string>


typedef std::vector<std::string> token_t;
typedef struct
{
    unsigned id; /// индекс слова в словаре
    std::string word;
    std::vector<double> vec; /// вектор слова типа double
} dictelem_t;



#endif /* dataStructs_hpp */
