#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include "lib.h"

struct Studentas{
    std::string vardas;
    std::string pavarde;
    int tarpRezSk;
    std::vector<int> tarpRez;
    int egzamRez;
    int vidurkis, mediana;
};

void input(Studentas &Lok);
void output(Studentas Lok);
void clean(Studentas &Lok);

#endif