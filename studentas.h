#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include "lib.h"

struct Studentas{
    std::string vardas;
    std::string pavarde;
    std::vector<int> tarpRez;
    int egzamRez;
    double vidurkis, mediana;
    std::vector<int> balai;
    double galutinis;
};

void inputManual(std::vector<Studentas> &studentai, int studSk, int vidMed);
void inputManualList(std::list<Studentas> &studentaiList, int studSk, int vidMed);
void inputScan(std::vector<Studentas> &studentai);
void outputManual(Studentas Lok, int vidMed);
void outputScan(std::vector<Studentas> &studentai);
void clean(Studentas &Lok);
void generateInfo(int studGenSk, int ndGenSk);
void inputSplitSort(std::string failoPav, int rusiavKateg, bool useVector);
// void inputSplitSortList(std::string failoPav, int rusiavKateg);

#endif