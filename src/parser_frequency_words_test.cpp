#include "parser_frequency_words_test.h"

string parser_frequency_words_test::start()
{
    try
    {
        string s;
        cout << "file name argument missing. do you start testing with \"test_input.txt\" and \"test_output.txt\"? [y/n]:";
        cin >> s;
        if(s=="y")
        {
            parser_frequency_words pfw;
            pfw.start("../data/test_input.txt");
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
    }
    catch (...) {
        return "unexpected error in parser_frequency_words_test.h";
    }
    return "cancel\n";
}
