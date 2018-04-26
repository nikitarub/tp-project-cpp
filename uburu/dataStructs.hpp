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
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <forward_list>
#include <string>
#include <vector>


typedef std::vector<std::string> token_t;
typedef struct
{
    unsigned long id; /// индекс слова в словаре
    std::string word;
    std::vector<double> vec; /// вектор слова типа double
} dictelem_t;


template<class K, class V>
struct Bucket {
    K key;
    V val;
    Bucket(const K &k, const V &v) : val(v), key(k) {}
};


template<class T> struct myHash {
    static size_t hashFunction(const T& s) {
        return std::hash<T>()(s);
    }
};

#endif /* dataStructs_hpp */
