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



