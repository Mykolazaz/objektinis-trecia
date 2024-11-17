#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include "lib.h"


class StudentasClass{
private:
    std::string vardas_;
    std::string pavarde_;
    std::vector<int> tarpRez_;
    int egzamRez_;
    double vidurkis_;
    double mediana_;
    double galutinis_;
    bool islaike_;

    // Privatūs pagalbiniai metodai
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
    
    // Set'eriai
    void setVardas(const std::string& vardas) { vardas_ = vardas; }
    void setPavarde(const std::string& pavarde) { pavarde_ = pavarde; }
    void setEgzamRez(int rez) { 
        egzamRez_ = rez; 
        rastiGalutini();
    }
    
    // Metodai
    void setTarpRez(const std::vector<int>& naujiTarpRez) {
        tarpRez_ = naujiTarpRez;
        rastiRez();
        rastiGalutini();
    }

    void pridetiTarpRez(int rez) {
        tarpRez_.push_back(rez);
        rastiRez();
        rastiGalutini();
    }

    void generuotiBalus(int kiekBalu = 15) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(0, 10);

        egzamRez_ = dist(mt);
        tarpRez_.clear();
        tarpRez_.reserve(kiekBalu);
        
        for (int i = 0; i < kiekBalu; i++) {
            tarpRez_.push_back(dist(mt));
        }
        
        rastiRez();
        rastiGalutini();
        rastiIslaike();
    }

    void rastiGalutini(bool naudotiVidurki = true) {
        galutinis_ = naudotiVidurki ? 
                   0.4 * vidurkis_ + 0.6 * egzamRez_ :
                   0.4 * mediana_ + 0.6 * egzamRez_;
        rastiIslaike();
    }

    void clear() {
        vardas_.clear();
        pavarde_.clear();
        tarpRez_.clear();
        egzamRez_ = 0;
        vidurkis_ = 0.0;
        mediana_ = 0.0;
        galutinis_ = 0.0;
    }

    void rastiIslaike(){
        islaike_ = (galutinis_ >= 5.0);
    }

    bool arIslaike() const {
        return islaike_;
    }

    bool compare(const StudentasClass& b, int criteria = 2) {
        switch (criteria) {
            case 0:
                return this->vardas_ > b.vardas_;
            case 1:
                return this->pavarde_ > b.pavarde_;
            case 2:
                return this->galutinis_ > b.galutinis_;
        }
    }
  
    //Friend'ai įvedimo ir išvedimo operacijoms
    friend std::istream& operator>>(std::istream& is, StudentasClass& s) {
        is >> s.vardas_ >> s.pavarde_;
        return is;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const StudentasClass& s) {
        os << std::left << std::setw(20) << s.pavarde_ << std::setw(20) << s.vardas_ 
            << std::setw(20) << std::setprecision(2) << std::fixed << s.galutinis_ << "\n";
        return os;
    }
};

void inputManual(std::vector<StudentasClass> &studentai, int studSk);
void inputManualList(std::list<StudentasClass> &studentaiList, int studSk);
void inputScan(std::vector<StudentasClass> &studentai, std::string failoPav);
void outputManual(StudentasClass Lok, int vidMed);
void outputScan(std::vector<StudentasClass> &studentai);
void generateEntries(int studGenSk, int ndGenSk);
void inputSplitSort(std::string failoPav, int rusiavKateg, int useVector, int testStrat);

#endif