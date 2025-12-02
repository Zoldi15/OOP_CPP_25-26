#include <iostream>

#include "SimpleTextGenerator.h"

using namespace std;

int main() {
    string text1="Now is not the time for sleep, now is the time for party!";
    SimpleTextGenerator gen1; gen1.trainFromText(text1);

    cout<<gen1.generate("now is", 10)<<endl;
    cout<<gen1.generate("time for", 20)<<endl<<endl;

    SimpleTextGenerator gen2; gen2.trainFromFile("test");
    return 0;
}