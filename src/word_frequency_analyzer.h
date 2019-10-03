//*********************************************************//
//                                                         //
//  word frequency analyzer                                //
//  created by Ilya Shishkin                               //
//  cortl@8iter.ru                                         //
//  http://8iter.ru                                        //
//  https://github.com/cortl0/word_frequency_analyzer_cpp  //
//  licensed by GPL v3.0                                   //
//                                                         //
//*********************************************************//

#ifndef WORD_FREQUENCY_ANALYZER_H
#define WORD_FREQUENCY_ANALYZER_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

using namespace std;

class word_frequency_analyzer
{

//This is a rule for determining the characters of a word
//The word can contain Latin characters
//Other characters are delimiters
//Any number of delimiters in a row is one delimiter
#define rule ((c > 64) && (c < 91)) || ((c > 96) && (c < 123))

public:
    int start(const char *in_file_name,  const char *out_file_name);
};

#endif // WORD_FREQUENCY_ANALYZER_H



