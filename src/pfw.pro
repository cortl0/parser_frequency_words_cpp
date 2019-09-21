# //********************************************************//
# //                                                        //
# //  parser frequency words C++ v0.1                       //
# //  created by Ilya Shishkin                              //
# //  cortl@yandex.ru                                       //
# //  www.8iter.ru                                          //
# //  https://github.com/cortl0/parser_frequency_words_cpp  //
# //  licensed by GPL v3.0                                  //
# //                                                        //
# //********************************************************//

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        parser_frequency_words.cpp \
        parser_frequency_words_test.cpp

HEADERS += \
    parser_frequency_words.h \
    parser_frequency_words_test.h
