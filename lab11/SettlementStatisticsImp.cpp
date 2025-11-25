//
// Created by User on 25-Nov-25.
//

#include "SettlementStatisticsImp.h"
#include "Settlement.h"

#include <fstream>
#include <set>
#include <sstream>

int SettlementStatisticsImp::numSettlements() {
    return Settlements.size();
}

int SettlementStatisticsImp::numCounties() {
    set<string> Counties;
    for (auto& s : Settlements) {
        Counties.insert(s.first);
    }
    return Counties.size();
}

int SettlementStatisticsImp::numSettlementsByCounty(const string& county) {
    int num=0;
    for (auto& s : Settlements) {
        if (s.first == county) num++;
    }
    return num;
}

vector<Settlement> SettlementStatisticsImp::findSettlementsByCounty(const string& county){
    vector<Settlement> found;
    for (auto& s : Settlements) {
        if (s.first == county) found.push_back(s.second);
    }
    return found;
}

Settlement SettlementStatisticsImp::findSettlementsByNameAndCounty(const string& name, const string& county){
    for (auto& s : Settlements) {
        if (s.first == county && s.second.getName()==name) return s.second;
    }
    return {"","",0};
}

Settlement SettlementStatisticsImp::maxPopulationBySettlement(){
    int max=0;
    Settlement found("","",0);
    for (auto& s : Settlements) {
        if (s.second.getPopulation()>max) {
            max=s.second.getPopulation();
            found=s.second;
        }
    }
    return found;
}

Settlement SettlementStatisticsImp::minPopulationBySettlement(){
    int min=INT_MAX;
    Settlement found("","",0);
    for (auto& s : Settlements) {
        if (s.second.getPopulation()<min) {
            min=s.second.getPopulation();
            found=s.second;
        }
    }
    return found;
}

vector<Settlement> SettlementStatisticsImp::findSettlementsByName(const string& name) override {
    vector<Settlement> found;
    for (auto& s : Settlements) {
        if (s.second.getName()==name) found.push_back(s.second);
    }
    return found;
}

void SettlementStatisticsImp::readFromFile(const string& filename){
    ifstream fin(filename);
    if (!fin){
        cerr<<"Nem talalhato file!\n";
        exit(1);
    }
    string line;
    while (getline(fin, line)){
        string name, county, popstr;
        int population;
        stringstream ss(line);
        getline(ss,name, ',');
        getline(ss,county, ',');
        getline(ss,popstr);
        stringstream ss1(popstr);
        ss1 >> population;

        Settlement s(name, county, population);

        this->Settlements.insert({county, s});
    }
}