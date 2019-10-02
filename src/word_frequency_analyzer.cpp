//*********************************************************//
//                                                         //
//  word frequency analyzer C++ v0.1                       //
//  created by Ilya Shishkin                               //
//  cortl@yandex.ru                                        //
//  www.8iter.ru                                           //
//  https://github.com/cortl0/word_frequency_analyzer_cpp  //
//  licensed by GPL v3.0                                   //
//                                                         //
//*********************************************************//

#include "word_frequency_analyzer.h"

int word_frequency_analyzer::start(const char *in_file_name,  const char *out_file_name)
{
    try {
        cout << "input file name is: " << in_file_name << endl;

        static const uint64_t char_buffer_length = 4096;
        char char_buffer[char_buffer_length];
        uint64_t char_buffer_shift;

        uint64_t count;
        char c;

        static const int word_length = 33;
        char word[word_length];
        int word_shift;

        ifstream in_file = ifstream(in_file_name, ios::in |ifstream::binary);
        if (in_file.is_open())
        {
            //building the map from the file
            map<string, uint64_t> words;
            map<string, uint64_t>::iterator it;
            in_file.seekg (0, in_file.end);
            const uint64_t in_file_length = static_cast<uint64_t>(in_file.tellg());
            in_file.seekg (0, in_file.beg);
            word_shift = 0;
            while(1)
            {
                count = in_file_length - static_cast<uint64_t>(in_file.tellg());
                if (!count)
                    break;
                if (count > char_buffer_length)
                    count = char_buffer_length;
                in_file.read (char_buffer, static_cast<streamsize>(count));
                char_buffer_shift = 0;
                while(char_buffer_shift < count)
                {
                    c = char_buffer[char_buffer_shift++];
                    if(rule)
                        word[word_shift++] = c;
                    else
                    {
                        if (word_shift == 0)
                            continue;
                        word[word_shift++] = '\0';
                        it = words.find(word);
                        if (it == words.end())
                            words.insert(make_pair(word, 1));
                        else
                            it->second++;
                        word_shift = 0;
                        continue;
                    }
                    if (word_shift > 32)
                        throw runtime_error("word_frequency_analyzer.h: word length greater than 32 characters");
                }
            }
            if (word_shift > 0)
            {
                word[word_shift++] = '\0';
                it = words.find(word);
                if (it == words.end())
                    words.insert(make_pair(word, 1));
                else
                    it->second++;
            }
            in_file.close();

            //invert key-value
            multimap<uint64_t, string> words_inv;
            for_each(words.begin(), words.end(), [&](pair<string, uint64_t> p)
            {
                words_inv.insert(make_pair(p.second, p.first));
            });

            //output the result to the file
            ofstream out_file = ofstream(out_file_name, ios::out | ifstream::binary);
            if(out_file.is_open())
            {
                uint64_t count_size = words_inv.size();
                //count_size = 100; // to display only the first 100 words
                uint64_t count_out = count_size;
                any_of(words_inv.rbegin(), words_inv.rend(), [&](pair<uint64_t, string> p)
                {
                    out_file << (count_size - count_out) << "\t\t" << p.first << "\t\t" << p.second << '\r' << '\n';
                    return !--count_out;
                });
                out_file.close();
            }
        }
        else {
            cout << "file " << in_file_name << " not found" << endl;
            return 1;
        }
    } catch (runtime_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    catch (...) {
        cout << "unexpected error in word_frequency_analyzer.h" << endl;
        return 1;
    }
    cout << "the file  " << out_file_name << " is ready" << endl;
    return 0;
}
