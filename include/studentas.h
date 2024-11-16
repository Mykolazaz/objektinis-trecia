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

class StudentasClass{
private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> tarpRez;
    int egzamRez;
    double vidurkis;
    double mediana;
    double galutinis;

    //Pagalbiniai metodai
    void rastiVid() {
        vidurkis = tarpRez.empty() ? 0.0 : 
                   accumulate(tarpRez.begin(), tarpRez.end(), 0.0) / tarpRez.size();
    }
    
    void rastiMed() {
        if (tarpRez.empty()) {
            mediana = 0.0;
            return;
        }
        
        std::vector<int> sorted = tarpRez;
        sort(sorted.begin(), sorted.end());
        size_t n = sorted.size();
        mediana = (n % 2 == 0) ? 
                  (sorted[n/2 - 1] + sorted[n/2]) / 2.0 : 
                  sorted[n/2];
    }
};

void inputManual(std::vector<Studentas> &studentai, int studSk);
void inputManualList(std::list<Studentas> &studentaiList, int studSk);
void inputScan(std::vector<Studentas> &studentai, std::string failoPav);
void outputManual(Studentas Lok, int vidMed);
void outputScan(std::vector<Studentas> &studentai);
void clean(Studentas &Lok);
void generateEntries(int studGenSk, int ndGenSk);
void inputSplitSort(std::string failoPav, int rusiavKateg, int useVector, int testStrat);

#endif