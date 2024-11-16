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
    std::string vardas_;
    std::string pavarde_;
    std::vector<int> tarpRez_;
    int egzamRez_;
    double vidurkis_;
    double mediana_;
    double galutinis_;

    //Pagalbiniai metodai
    void rastiVid() {
        vidurkis_ = tarpRez_.empty() ? 0.0 : 
                   accumulate(tarpRez_.begin(), tarpRez_.end(), 0.0) / tarpRez_.size();
    }
    
    void rastiMed() {
        if (tarpRez_.empty()) {
            mediana_ = 0.0;
            return;
        }
        
        std::vector<int> sorted = tarpRez_;
        sort(sorted.begin(), sorted.end());
        size_t n = sorted.size();
        mediana_ = (n % 2 == 0) ? 
                  (sorted[n/2 - 1] + sorted[n/2]) / 2.0 : 
                  sorted[n/2];
    }

    void rastiRez() {
        rastiVid();
        rastiMed();
    }

public:
    // Konstruktoriai
    StudentasClass() : 
        egzamRez_(0), 
        vidurkis_(0.0), 
        mediana_(0.0), 
        galutinis_(0.0) {}
    
    StudentasClass(const std::string& vardas, const std::string& pavarde) : 
        vardas_(vardas), 
        pavarde_(pavarde), 
        egzamRez_(0), 
        vidurkis_(0.0), 
        mediana_(0.0), 
        galutinis_(0.0) {}

    ~StudentasClass() = default;

    // Get'eriai
    const std::string& getVardas() const { return vardas_; }
    const std::string& getPavarde() const { return pavarde_; }
    const std::vector<int>& getTarpRez() const { return tarpRez_; }
    int getEgzamRez() const { return egzamRez_; }
    double getVidurkis() const { return vidurkis_; }
    double getMediana() const { return mediana_; }
    double getGalutinis() const { return galutinis_; }
    
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