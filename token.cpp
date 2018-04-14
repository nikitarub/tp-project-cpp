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
	// std::vector<std:string> array_of_sentences // вектор предложений
};


Token::Token(std::ifstream& input){
	std::string line;
	while (getline(input, line)){
		text = text + line;
	}
}



std::vector<std::string> Token::sentence_token(){
	std::vector<std::string> array_of_sentences; // вектор предложений
	// typedef boost::tokenizer<boost::char_separator<char>> tk;
	boost::char_separator<char> sep("!?.");
	boost::tokenizer<boost::char_separator<char>> tokens(text, sep);
	for (boost::tokenizer<boost::char_separator<char>>::iterator it = tokens.begin(); it != tokens.end(); ++it){
		array_of_sentences.push_back(*it);
		// std::cout << *it << '\n';		
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
	std::vector<std::vector<std::string>> array_of_sep_sentences; // вектор предложений разбитых на слова
	std::vector<std::string> sents = sentence_token(); // получаем вектор неразбитых предложений
	std::vector<std::string> sep_sentences;
	std::cout << '1';
	std::vector<std::string> sent = normalize(sents);
	std::cout << '2';
	boost::char_separator<char> sep(" ");


	for (int i = 0; i < sent.size(); ++i){
		boost::tokenizer<boost::char_separator<char>> tokens(sent[i], sep);
		for (boost::tokenizer<boost::char_separator<char>>::iterator it = tokens.begin(); it != tokens.end(); ++it){
			sep_sentences.push_back(*it);
		// std::cout << *it << '\n';		
		}
		array_of_sep_sentences.push_back(sep_sentences);
	}

}





// std::vector<std::vector<std::string>> Token::sentence_to_words(){

// 	std::vector<std::vector<std::string>> array_of_sep_sentences; // вектор предложений разбитых на слова
// 	std::vector<std::string> sent = sentence_token(); // получаем вектор неразбитых предложений
// 	std::vector<std::string> sep_sentence;
//  	std::smatch m;
// 	std::regex e ("[а-яА-Я]+");

// 	for (int i = 0; i < sent.size(); ++i){
// 		std::regex_search(sent[i], m, e);
// 		// std::cout << sent[i] << '\n';
// 		for (auto x:m) std::cout << x << '\n';//sep_sentence.push_back(x);	
		
// 		array_of_sep_sentences.push_back(sep_sentence);
// 	}

// 	return array_of_sep_sentences;

// }

// std::vector<std::vector<std::string>> Token::sentence_to_words(){
//     std::vector<std::vector<std::string>> array_of_sep_sentences; // вектор предложений разбитых на слова
// 	std::vector<std::string> sent = sentence_token(); // получаем вектор неразбитых предложений
// 	std::vector<std::string> sep_sentence; // предложение разбитое на слова

// 	std::regex rgx ("[А-Яа-я]");
// 	// for (std::vector<std::string>::iterator it = sent.begin(); it != sent.end(); ++it){
// 	for (int i = 0; i < sent.size(); ++i){


// 		// std::cout << sent[i] << '\n';
// 		// std::sregex_token_iterator iter(sent[i].begin(), sent[i].end(), rgx, -1);
//   //     	std::sregex_token_iterator end;
//   //     	while (iter != end){
//   //         //std::cout << "S43:" << *iter << std::endl;
//   //       	sep_sentence.push_back(*iter);
//   //         	++iter;
//   //    	}

//      	array_of_sep_sentences.push_back(sep_sentence);

// 	}
// 	return array_of_sep_sentences;

// }





int main(int argc, char const *argv[])
{
	std::vector<std::string> sent; // вектор неразбитых предложений
	std::vector<std::vector<std::string>> array_of_sep_sentences; // вектор предложений разбитых на слова

	std::ifstream fin("test.txt");
	Token tk(fin);
	sent = tk.sentence_token();
	// for (std::vector<std::string>::iterator it = sent.begin(); it != sent.end(); ++it){
	// 	std::cout << *it << '\n';
	// }

	array_of_sep_sentences = tk.sentence_to_words();

	// for (std::vector<std::vector<std::string>>::iterator it = array_of_sep_sentences.begin(); it != array_of_sep_sentences.end(); ++it){
	// 	std::cout << *it << '\n';
	// }

	// for (auto el : array_of_sep_sentences) {
	// 	std::cout << el << std::endl;
	// }

	for (int i = 0; i < array_of_sep_sentences.size(); ++i){
		for (int j = 0; j < array_of_sep_sentences[i].size(); ++j){
			std::cout << array_of_sep_sentences[i][j];
		}
	}



	return 0;
}





// void sentence_token(std::ifstream& input){
// 	std::vector<std::string> array_of_sentences;
// 	std::string line; // содержит строку файла
// 	std::string text; // содержит в себе весь текст

// 	std::size_t pos_begin; // начало предложения
// 	std::size_t pos_end; // конец предложения 

// 	while (getline(input, line)) { // получение единой строки из текста
// 		text = text + line;
// 		// std::cout << sentence + '\n'; 
// 	}
// 	std::cout << text + "\n" << "----------------";

// 	// for ( std::string::iterator it=text.begin(); it!=text.end(); ++it){

// 	// 	if (*it == '!' || *it == '?' || *it == '.'){

// 	// 	}
// 	// }
//   	std::cout << '\n';

// }

// int main(int argc, char const *argv[])
// {

// 	std::ifstream fin("test.txt");
// 	sentence_token(fin);
	
// 	return 0;
// }


