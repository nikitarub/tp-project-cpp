cmake_minimum_required(VERSION 3.10)
project(uburu)

set(CMAKE_CXX_STANDARD 14)

add_executable(uburu main.cpp file_reader.h file_reader.cpp text_comparator.cpp text_comparator.h word_vector.cpp word_vector.h word_vector_table.cpp word_vector_table.h)