#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include "lib.h"

struct Studentas{
    std::string vardas;
    std::string pavarde;
    float tarpRezSk;
    std::vector<float> tarpRez;
    float egzamRez;
    float vidurkis, mediana;
};

void input(Studentas &Lok);
void output(Studentas Lok);
void clean(Studentas &Lok);

#endif