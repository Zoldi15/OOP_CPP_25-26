//
// Created by User on 25-Nov-25.
//

#ifndef SETTLEMENT_H
#define SETTLEMENT_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Settlement {
    string name="";
    string county="";
    int population=0;

public:

    Settlement(string name, string county, int population):name(name),county(county),population(population){}
    Settlement(const Settlement& s):name(s.getName()),county(s.getCounty()),population(s.getPopulation()){}

    string getName() const {return name;}
    string getCounty() const {return county;}
    int getPopulation() const {return population;}

    void setName(string name){this->name=move(name);}
    void setCounty(string county){this->county=move(county);}
    void setPopulation(int population){this->population=population;}

    friend istream& operator>>(istream& is, Settlement& st) {
        is>>st.name>>st.county>>st.population;
        return is;
    }
    void operator=(Settlement& st) {
        this->setName(st.getName());
        this->setCounty(st.getCounty());
        this->setPopulation(st.getPopulation());
    }
};

#endif //SETTLEMENT_H
