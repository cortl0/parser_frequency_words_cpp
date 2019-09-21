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
