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

#include "parser_frequency_words.h"
#include "parser_frequency_words_test.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    switch (argc)
    {
    case 1:
    {
        parser_frequency_words_test pfwt;
        cout << pfwt.start() << endl;
        break;
    }
    case 2:
    {
        cout << "input file name is: " << argv[1] << endl;
        parser_frequency_words pfw;
        if (!pfw.start(argv[1]))
            cout << "the file \"output.txt\" is ready" << endl;
        else
            cout << "task failed" << endl;
        break;
    }
    }
    return 0;
}
