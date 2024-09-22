#include "lib.h"
#include "studentas.h"

double mediana(std::vector<int> &v){
    size_t n = v.size();
    sort(v.begin(), v.end());
    if (n % 2 == 0) {
        return (v[n/2 - 1] + v[n/2]) / 2.0;
    } else {
        return v[n/2];
    }
}

void inputManual(Studentas &Lok){
    int arRandom;
    std::string input;
    bool praeitasBuvoTuscias = false;

    std::cout << "Ar atsitiktinai generuoti sekančio studento balus? (0 arba 1):" << std::endl;
    std::cin >> arRandom;

    std::cout << "Įveskite studento vardą ir pavardę:" << std::endl;
    std::cin >> Lok.vardas >> Lok.pavarde;
    
    if (arRandom == 0){
        std::cout << "Įveskite egzamino rezultatą: " << std::endl;
        std::cin >> Lok.egzamRez;
        std::cout << "Į vieną eilutę įveskite tarpinius rezultatus (2 ENTER paspausdimai stabdo įvedimą):" << std::endl;

        while (true) {
            std::getline(std::cin, input);

            if (input.empty()) {
                if (praeitasBuvoTuscias) {
                    break;
                }
                praeitasBuvoTuscias = true;
            } else {
                praeitasBuvoTuscias = false;

                std::stringstream ss(input);
                int skaicius;
                
                while (ss >> skaicius) {
                    Lok.tarpRez.push_back(skaicius);
                }
            }
        }
    } else {
        std::srand(std::time(0));
        Lok.egzamRez = rand() % 10 + 1;
        for (int i = 0; i < 5; i++){
            Lok.tarpRez.push_back(rand() % 10 + 1);
        }
    }
    
}

void inputScan(std::vector<Studentas> &studentai) {
    std::ifstream fr("kursiokai.txt");
    std::string eilute;

    std::getline(fr, eilute);

    while (std::getline(fr, eilute)) {
        std::istringstream iss(eilute);
        Studentas Lok;

        iss >> Lok.pavarde >> Lok.vardas;

        int balas;
        while (iss >> balas) {
            Lok.balai.push_back(balas);
        }

        if (!Lok.balai.empty()) {
            Lok.egzamRez = Lok.balai.back();
            Lok.balai.pop_back();
            Lok.tarpRez = Lok.balai;
        }

        studentai.push_back(Lok);
    }

    fr.close();
}


void outputManual(Studentas Lok, int vidMed){
    
    if(vidMed == 0){
        double vidurkis = (accumulate(Lok.tarpRez.begin(), Lok.tarpRez.end(), 0.0)+Lok.egzamRez)/(Lok.tarpRez.size() + 1);

        std::cout << std::left << std::setw(20) << Lok.pavarde
        << std::setw(20) << Lok.vardas << std::setw(20)<< std::setprecision(2) << std::fixed <<
        vidurkis << std::endl;
    } else {
        std::vector<int> visiRez = Lok.tarpRez;
        visiRez.push_back(Lok.egzamRez);
        double med = mediana(visiRez);

        std::cout << std::left << std::setw(20) << Lok.pavarde
        << std::setw(20) << Lok.vardas << std::setw(20) << std::setprecision(2) << std::fixed <<
        med << std::endl;
    }
    
}

void outputScan(std::vector<Studentas> &studentai){

    std::sort(studentai.begin(), studentai.end(), 
              [](const Studentas &a, const Studentas &b) {
                  return a.pavarde < b.pavarde;
              });
    
    for (const auto &stud : studentai){
        double vidurkis = (accumulate(stud.tarpRez.begin(), stud.tarpRez.end(), 0.0)+stud.egzamRez)/(stud.tarpRez.size() + 1);

        std::vector<int> visiRez = stud.tarpRez;
        visiRez.push_back(stud.egzamRez);
        double med = mediana(visiRez);

        std::cout << std::left << std::setw(20) << stud.pavarde;
        std::cout << std::left << std::setw(20) << stud.vardas;
        std::cout << std::left << std::setw(20) << std::setprecision(2) << std::fixed <<
        vidurkis << std::left << std::setw(20) << std::setprecision(2) << std::fixed << med << std::endl;
    }
}

void clean(Studentas &Lok){
    Lok.vardas.clear();
    Lok.pavarde.clear();
    Lok.tarpRez.clear();
    Lok.balai.clear();
}

void generate(int studGenSk, int ndGenSk){
    std::ofstream fw("kursiokai.txt");

    studGenSk += 1;
    ndGenSk += 1;

    fw << std::left << std::setw(15) << std::setfill(' ') << "Pavardė"
    << std::setw(15) << std::setfill(' ') << "Vardas";
    for (int i = 1; i < ndGenSk; i++){
        fw << "ND" << std::setw(2) << std::left << i << " ";
    }
    fw << std::setw(10) << "Egzaminimas" << std::endl;
    
    for (int i = 1; i < studGenSk; i++){
        fw << std::left << std::setw(15) << ("Pavardė"+std::to_string(i))
        << std::setw(15) << ("Vardas"+std::to_string(i));
        for (int j = 1; j < ndGenSk; j++){
            fw << std::setw(5) << rand() % 10 + 1;    
        }
        fw << std::setw(10) << rand() % 10 + 1 << std::endl;
    }
    fw.close();
}