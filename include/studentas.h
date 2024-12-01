#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include "lib.h"

class Human {
protected:
    std::string vardas_;
    std::string pavarde_;
};

class StudentasClass : public Human{
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
    void rastiVid();
    void rastiMed();
    void rastiRez();

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

    ~StudentasClass(){
        tarpRez_.clear();
    };

    StudentasClass(const StudentasClass& other) :
        vardas_(other.vardas_),
        pavarde_(other.pavarde_),
        tarpRez_(other.tarpRez_),
        egzamRez_(other.egzamRez_),
        vidurkis_(other.vidurkis_),
        mediana_(other.mediana_),
        galutinis_(other.galutinis_),
        islaike_(other.islaike_) {}

    StudentasClass& operator=(const StudentasClass& other) {
        if (this != &other) {  // Apsauga nuo savęs priskyrimo
            vardas_ = other.vardas_;
            pavarde_ = other.pavarde_;
            tarpRez_ = other.tarpRez_;
            egzamRez_ = other.egzamRez_;
            vidurkis_ = other.vidurkis_;
            mediana_ = other.mediana_;
            galutinis_ = other.galutinis_;
            islaike_ = other.islaike_;
        }
        return *this;
    }

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
    void setEgzamRez(int rez) { egzamRez_ = rez; rastiGalutini(); }
    
    // Metodai
    void setTarpRez(const std::vector<int>& naujiTarpRez);
    void pridetiTarpRez(int rez);
    void generuotiBalus(int kiekBalu = 15);
    void rastiGalutini(bool naudotiVidurki = true);
    void clear();
    void rastiIslaike(){ islaike_ = (galutinis_ >= 5.0); }
    bool arIslaike() const { return islaike_; }
    bool compare(const StudentasClass& b, int criteria = 2);
  
    //Friend'ai įvedimo ir išvedimo operacijoms
    friend std::istream& operator>>(std::istream& is, StudentasClass& s);
    friend std::ostream& operator<<(std::ostream& os, const StudentasClass& s);
};

void inputManual(std::vector<StudentasClass> &studentai, int studSk);
void inputManualList(std::list<StudentasClass> &studentaiList, int studSk);
void inputScan(std::vector<StudentasClass> &studentai, std::string failoPav);
void outputManual(StudentasClass Lok, int vidMed);
void outputScan(std::vector<StudentasClass> &studentai);
void generateEntries(int studGenSk, int ndGenSk);
void inputSplitSort(std::string failoPav, int rusiavKateg, int useVector, int testStrat);

#endif