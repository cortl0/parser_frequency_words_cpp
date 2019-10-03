# //*********************************************************//
# //                                                         //
# //  word frequency analyzer                                //
# //  created by Ilya Shishkin                               //
# //  cortl@8iter.ru                                         //
# //  http://8iter.ru                                        //
# //  https://github.com/cortl0/word_frequency_analyzer_cpp  //
# //  licensed by GPL v3.0                                   //
# //                                                         //
# //*********************************************************//

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        word_frequency_analyzer.cpp \
        word_frequency_analyzer_test.cpp

HEADERS += \
    word_frequency_analyzer.h \
    word_frequency_analyzer_test.h
