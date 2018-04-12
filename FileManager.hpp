//
//  FileManager.hpp
//  project_cpp_xcode
//
//  Created by Nikita on 11.04.18.
//  Copyright © 2018 RIT. All rights reserved.
//

#ifndef FileManager_hpp
#define FileManager_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "dataStructs.hpp"

class FileManager
{
protected:
    std::vector<token_t> tokens; /// массив слов (токенов)
    std::vector<dictelem_t> dict; /// словарь w2v
    std::string text; /// текст для токенизации
    
public:
    FileManager();
    ~FileManager();
    bool ReadText(std::ifstream& file); /// считывает весь текст в строку
    bool WriteTokens(std::ofstream& file);
    
    bool ReadDict(std::ifstream& file); /// считывает массив структур словаря (id, word, vec)
    bool ReadTokens(std::ifstream& file); /// считывает массив слов (токенов)
    void WriteIndexes(std::ofstream& file);
    void WriteNFWords(std::ofstream& file);
    
    void ReadIndexes();
    void WriteMarkups();
};

#endif /* FileManager_hpp */
