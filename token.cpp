#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <boost/tokenizer.hpp>
#include <regex>




class Token 
{

public:
	Token(std::ifstream& input); // конструктор
	~Token(){};
	std::vector<std::string> sentence_token(); // разделение на предлажения
	std::vector<std::vector<std::string>> sentence_to_words();
	std::vector<std::string> normalize(std::vector<std::string>& array);
private:
	std::string text; // сам текст
};


Token::Token(std::ifstream& input){
	std::string line;
	while (getline(input, line)){
		text = text + line;
	}
}



std::vector<std::string> Token::sentence_token(){
	std::vector<std::string> array_of_sentences; // вектор предложений
	boost::char_separator<char> sep("!?.");
	boost::tokenizer<boost::char_separator<char>> tokens(text, sep);
	for (boost::tokenizer<boost::char_separator<char>>::iterator it = tokens.begin(); it != tokens.end(); ++it){
		array_of_sentences.push_back(*it);
	}
	return array_of_sentences;
}


std::vector<std::string> Token::normalize(std::vector<std::string>& array){
	std::string signes ("()-<>/[]{}|*");
	for (int i = 0; i < array.size(); ++i){
		for (int j = 0; j < array[i].size(); ++j){
			if (signes.find(array[i][j]) != std::string::npos){
				array[i].erase(array[i].begin()+j);
			}
		}
	}
	return array;	
}

std::vector<std::vector<std::string>> Token::sentence_to_words(){
	std::vector<std::vector<std::string>> array_of_sep_sentences;
	std::vector<std::string> sep_sentence;
	std::vector<std::string> normalized_sent;
	std::vector<std::string> none_sep_sent = sentence_token(); // получаем вектор предложений из текста
	normalized_sent = normalize(none_sep_sent); // получаем вектор нормализированных предложений

	boost::char_separator<char> sep(" ");
	for (int i = 0; i < normalized_sent.size(); ++i){ // идем по векторы нормализованных предложений
		boost::tokenizer<boost::char_separator<char>> tokens(normalized_sent[i], sep);
		for (boost::tokenizer<boost::char_separator<char>>::iterator it = tokens.begin(); it != tokens.end(); ++it){ // идем по одному предлодению
			sep_sentence.push_back(*it);
		}
		array_of_sep_sentences.push_back(sep_sentence);
	}

	return array_of_sep_sentences;

}


int main(int argc, char const *argv[])
{
	std::vector<std::string> sent, norm; // вектор неразбитых предложений
	std::vector<std::vector<std::string>> array_of_sep_sentences; // вектор предложений разбитых на слова

	std::ifstream fin("test.txt");
	Token tk(fin);
	sent = tk.sentence_token();

	std::cout << "-------------separated senteces-------------------" << std::endl;
	for (std::vector<std::string>::iterator it = sent.begin(); it != sent.end(); ++it){
		std::cout << *it << '\n';
	}

	std::cout << "-------------normalized-------------------" << std::endl;


	norm = tk.normalize(sent);
	for (auto el : norm){
		std::cout << el << std::endl;
	}

	std::cout << "-------------separated words-------------------" << std::endl;

	array_of_sep_sentences = tk.sentence_to_words();
	for (auto sentence : array_of_sep_sentences){
		for (auto word : sentence){
			std::cout << word << std::endl;
		}
	}
	return 0;
}
