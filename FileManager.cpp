//
//  FileManager.cpp
//  project_cpp_xcode
//
//  Created by Nikita on 11.04.18.
//  Copyright © 2018 RIT. All rights reserved.
//

#include "FileManager.hpp"


bool FileManager::ReadText(std::ifstream& file)
{
    std::vector<std::string> array_of_sentences;
    std::string line; // содержит строку файла
    std::string text; // содержит в себе весь текст
    
    if (file.eof() || !file.is_open())
        return 0;
    
    while (std::getline(file, line)) // получение единой строки из текстаs
        text = text + line;
    
    return 1;
}
bool FileManager::WriteTokens(std::ofstream& file)
{
    return 1;
}


bool FileManager::ReadDict(std::ifstream& file)
{
    
    return 1;
};


bool FileManager::ReadTokens(std::ifstream& file)
{
//    getline(stream, , separator);
    std::string str;
    while (std::getline(file, str, '\n'))
    {
        //
    }
    return 1;
};
