//
// Created by User on 02-Dec-25.
//

#ifndef TEXTGENERATOR_H
#define TEXTGENERATOR_H

#include <string>

using namespace std;

class TextGenerator {
public:
    virtual void trainFromText(string trainingText) = 0;
    virtual void trainFromFile(string filename) = 0;
    virtual string generate(string startWords, int numWords=10) = 0;
    //virtual ~TextGenerator() = default;
};


#endif //TEXTGENERATOR_H
