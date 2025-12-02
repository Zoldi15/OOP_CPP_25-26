//
// Created by User on 02-Dec-25.
//

#ifndef SIMPLETEXTGENERATOR_H
#define SIMPLETEXTGENERATOR_H

#include <unordered_map>
#include <vector>
#include "TextGenerator.h"

using namespace std;

class SimpleTextGenerator : public TextGenerator {
    unordered_map<string, vector<string>> stats;
public:
    void trainFromText(string trainingText) override;
    void trainFromFile(string filename) override;
    string generate(string startWords, int numWords=10) override;
};

#endif //SIMPLETEXTGENERATOR_H
