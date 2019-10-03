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

#include "word_frequency_analyzer_test.h"

string word_frequency_analyzer_test::start()
{
    try
    {
        word_frequency_analyzer wfa;
        if (wfa.start("../data/test_input.txt", "../data/output.txt"))
            return "test failed";
        ifstream file_0 = ifstream("../data/test_output.txt", ios::in |ifstream::binary);
        if (!file_0.is_open())
            return "test failed";
        ifstream file_1 = ifstream("../data/output.txt", ios::in |ifstream::binary);
        if (!file_1.is_open())
            return "test failed";
        file_0.seekg (0, file_0.end);
        file_1.seekg (0, file_1.end);
        if(file_0.tellg() != file_1.tellg())
            return "test failed";
        file_0.seekg (0, file_0.beg);
        file_1.seekg (0, file_1.beg);
        char c_0[1];
        char c_1[1];
        while(!file_0.eof())
        {
            file_0.read(c_0, 1);
            file_1.read(c_1, 1);
            if (c_0[0] != c_1[0])
                return "test failed";
        }
        file_0.close();
        file_1.close();
        return "test passed";
    }
    catch (...) {
        return "unexpected error in word_frequency_analyzer_test.h";
    }
}
