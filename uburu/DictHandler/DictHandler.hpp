#ifndef DictHandler_hpp
#define DictHandler_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "dataStructs.hpp"


template<class K, class V, class HashGenerator = myHash<K> >
class Model {
public:
    int size = 8;
    std::vector<std::vector<Bucket<K, V> > > table;
    Model() {
        for(int i = 0; i < size; i++) {
            std::vector<Bucket<K, V> > v;
            table.push_back(v);
        }
    }
    ~Model() {}
    void set(const K &k, const V &v) {
        Bucket<K, V> b(k, v);
        for(int i = 0; i < table[hash(k)].size(); i++)
            if(table[hash(k)][i].key == k) {
                table[hash(k)][i] = b;
                return;
            }
        table[hash(k)].push_back(b);
    }
    V get(const K &k) {
        int i = 0;
        for(; i < table[hash(k)].size(); i++)
            if(table[hash(k)][i].key == k)
                break;
        
        return table[hash(k)][i].val;
        
    }
    bool exist(const K &k) {
        for(int i = 0; i < table[hash(k)].size(); i++)
            if(table[hash(k)][i].key == k)
                return true;
        return false;
    }
    size_t hash(const K &k) {
        return HashGenerator::hashFunction(k) % table.size();
    }
};




class DictHandler
{
    Model<std::string, dictelem_t> model;
    Model<unsigned long, dictelem_t> model_vec;
public:
    DictHandler(){}
    ~DictHandler(){}
    
    void fit(std::ifstream& file);
    unsigned long getId(std::string key);
    std::vector<double> getVecbyId(const unsigned long req_id);
    
    bool dropNF;
};


#endif /* DictHandler_hpp */

