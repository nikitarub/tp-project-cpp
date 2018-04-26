#include "DictHandler.hpp"


void DictHandler::fit(std::ifstream& file)
{
    std::string s;
    
//    if (file.eof() || !file.is_open())
//        return 0;
    
    while (std::getline(file, s)) // получение единой строки из текстаs
    {
        std::string delimiter = " ";
        std::string delimiter_vec = ",";
        
        unsigned long id = 0;
        std::string word;
        std::vector<double> vec;
        
        int i = 0;
        size_t pos = 0;
        std::string token;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            if (i == 0)
                id = atoi(token.c_str());
            else if (i == 1)
                word = token;
            
            s.erase(0, pos + delimiter.length());
            i++;
        }
        while ((pos = s.find(delimiter_vec)) != std::string::npos) {
            token = s.substr(0, pos);
            vec.push_back(atof(token.c_str()));
            s.erase(0, pos + delimiter_vec.length());
        }
        vec.push_back(atof(s.c_str()));
        
        dictelem_t elem;
        elem.id = id;
        elem.word = word;
        elem.vec = vec;
        
        model.set(word, elem);
        model_vec.set(id, elem);
        
    }
};


unsigned long DictHandler::getId(const std::string key)
{
    dictelem_t elem;
    bool exist = false;
    exist = model.exist(key);
    if (!exist)
        return 0;
    elem = model.get(key);
    return elem.id;
};


std::vector<double> DictHandler::getVecbyId(const unsigned long req_id)
{
    dictelem_t elem;
    try {
        bool exist = false;
        exist = model_vec.exist(req_id);
    } catch (bool exist) {
        std::cout << "Required id does not exist!" << std::endl; // TODO throw erorr
    }
    elem = model_vec.get(req_id);
    return elem.vec;
};

