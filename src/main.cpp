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

#include "word_frequency_analyzer.h"
#include "word_frequency_analyzer_test.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    switch (argc)
    {
    case 1:
    {
        string s;
        cout << "file name argument missing. do you start testing with \"test_input.txt\" and \"test_output.txt\"? [y/n]:";
        cin >> s;
        if(s == "y")
        {
            word_frequency_analyzer_test wfat;
            cout << wfat.start() << endl;
        }
        else
            cout << "cancel" << endl;
        break;
    }
    case 2:
    {
        word_frequency_analyzer wfa;
        if (wfa.start(argv[1], "../data/output.txt"))
            cout << "analysis failed" << endl;
        break;
    }
    case 3:
    {
        word_frequency_analyzer wfa;
        if (wfa.start(argv[1], argv[2]))
            cout << "analysis failed" << endl;
        break;
    }
    }
    return 0;
}
