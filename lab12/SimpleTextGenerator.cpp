//
// Created by User on 02-Dec-25.
//

#include "SimpleTextGenerator.h"

#include <iostream>
#include <sstream>
#include <ctype.h>
#include <fstream>

string CleanWords(string words) {
    string output;
    for (auto c: words) {
        c=tolower(c);
        if(isalpha(c)) output+=c;
    }
    return output;
}

void SimpleTextGenerator::trainFromText(string trainingText) {
    istringstream is(trainingText);
    string word;
    vector<string> words;

    while(is>>word) {
        string ns=CleanWords(word);
        words.push_back(ns);
        //cout<<ns<<" ";
    }

    if(words.size()<3) {
        cout<<"Not enough words!"<<endl;
        exit(1);
    }
    for(int i=0;i<words.size()-1;i++) {
        string bigram=words[i]+" "+words[i+1];

        unordered_map<string,vector<string>>::iterator it=this->stats.find(bigram);
        if(it!=this->stats.end()) {
            if(i+2 < words.size()) it->second.push_back(words[i+2]);
        } else {
            vector<string> value;
            if(i+2 < words.size()) value.push_back(words[i+2]);
            this->stats.insert({bigram,value});
        }
    }

    cout<<"Mapping: "<<endl;
    for (auto &pair: this->stats) {
        cout<<pair.first<<": ";
        for (auto &word: pair.second) {
            cout<<word<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void SimpleTextGenerator::trainFromFile(string filename) {
    ifstream f(filename);
    if(!f.is_open()) exit(2);
    string word;
    vector<string> words;

    while(f>>word) {
        string ns=CleanWords(word);
        words.push_back(ns);
        //cout<<ns<<" ";
    }

    if(words.size()<3) {
        cout<<"Not enough words!"<<endl;
        exit(1);
    }
    for(int i=0;i<words.size()-1;i++) {
        string bigram=words[i]+" "+words[i+1];

        unordered_map<string,vector<string>>::iterator it=this->stats.find(bigram);
        if(it!=this->stats.end()) {
            if(i+2 < words.size()) it->second.push_back(words[i+2]);
        } else {
            vector<string> value;
            if(i+2 < words.size()) value.push_back(words[i+2]);
            this->stats.insert({bigram,value});
        }
    }

    cout<<"Mapping: "<<endl;
    for (auto &pair: this->stats) {
        cout<<pair.first<<": ";
        for (auto &word: pair.second) {
            cout<<word<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    f.close();
}

string SimpleTextGenerator::generate(string startWords, int numWords) {
    srand(time(0));
    //ostringstream generatedText (startWords+" ");
    string generatedText (startWords+" ");

    for(int i=0;i<numWords;i++) {
        auto it=stats.find(startWords);
        if(it == stats.end()) return generatedText;

        int size=it->second.size(); if(size==0) return generatedText;
        int nr=rand()%size;

        string newWord=it->second[nr];
        generatedText+=it->second[nr]+" ";

        stringstream in(startWords);
        string w; in >> w; in >> w; //szokozig olvas
        startWords = w + " " + newWord;
    }
    return generatedText;
}
