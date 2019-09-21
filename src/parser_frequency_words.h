//********************************************************//
//                                                        //
//  parser frequency words C++ v0.1                       //
//  created by Ilya Shishkin                              //
//  cortl@yandex.ru                                       //
//  www.8iter.ru                                          //
//  https://github.com/cortl0/parser_frequency_words_cpp  //
//  licensed by GPL v3.0                                  //
//                                                        //
//********************************************************//

#ifndef PARSER_FREQUENCY_WORDS_H
#define PARSER_FREQUENCY_WORDS_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

using namespace std;

class parser_frequency_words
{

//This is a rule for determining the characters of a word
//The word can contain Latin characters
//Other characters are delimiters
//Any number of delimiters in a row is one delimiter
#define rule ((c > 64) && (c < 91)) || ((c > 96) && (c < 123))

public:
    int start(const char *file_name);
};

#endif // PARSER_FREQUENCY_WORDS_H



