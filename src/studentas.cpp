#include "lib.h"
#include "studentas.h"

double mediana(std::vector<int> &v){
    size_t n = v.size();
    sort(v.begin(), v.end());
    if (n % 2 == 0) { //dviejų vidurinių variacinės eilutės skaičių vidurkis
        return (v[n/2 - 1] + v[n/2]) / 2.0;
    } else {
        return v[n/2];
    }
}

void inputManual(std::vector<Studentas> &studentai, int studSk){
    for (int i=0; i<studSk; i++){
        int arRandom;
        std::string input;
        bool praeitasBuvoTuscias = false;
        Studentas Lok;

        std::cout << "Ar atsitiktinai generuoti sekančio studento balus? (0 arba 1):" << "\n";
        std::cin >> arRandom;

        std::cout << "Įveskite studento vardą ir pavardę:" << "\n";
        std::cin >> Lok.vardas >> Lok.pavarde;
        
        if (arRandom == 0){
            std::cout << "Įveskite egzamino rezultatą: " << "\n";
            std::cin >> Lok.egzamRez;
            std::cout << "Į vieną eilutę įveskite tarpinius rezultatus (2 ENTER paspausdimai stabdo įvedimą):" << "\n";

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
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_int_distribution<int> dist(0, 10);

            Lok.egzamRez = dist(mt);
            for (int index = 0; index < 15; index++){
                Lok.tarpRez.push_back(dist(mt));
            }
        }
        studentai.push_back(Lok);
        clean(Lok);
    }
}

void inputManualList(std::list<Studentas> &studentaiList, int studSk){
    for (int i=0; i<studSk; i++){
        int arRandom;
        std::string input;
        bool praeitasBuvoTuscias = false;
        Studentas Lok;

        std::cout << "Ar atsitiktinai generuoti sekančio studento balus? (0 arba 1):" << "\n";
        std::cin >> arRandom;

        std::cout << "Įveskite studento vardą ir pavardę:" << "\n";
        std::cin >> Lok.vardas >> Lok.pavarde;
        
        if (arRandom == 0){
            std::cout << "Įveskite egzamino rezultatą: " << "\n";
            std::cin >> Lok.egzamRez;
            std::cout << "Į vieną eilutę įveskite tarpinius rezultatus (2 ENTER paspausdimai stabdo įvedimą):" << "\n";

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
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_int_distribution<int> dist(0, 10);

            Lok.egzamRez = dist(mt);
            for (int index = 0; index < 5; index++){
                Lok.tarpRez.push_back(dist(mt));
            }
        }
        studentaiList.push_back(Lok);
        clean(Lok);
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
        double galut_vidurkis = 0.4*(accumulate(Lok.tarpRez.begin(), Lok.tarpRez.end(), 0.0)/Lok.tarpRez.size()) + 0.6*Lok.egzamRez;

        std::cout << std::left << std::setw(20) << Lok.pavarde
        << std::setw(20) << Lok.vardas << std::setw(20)<< std::setprecision(2) << std::fixed <<
        galut_vidurkis << "\n";
    } else {
        double galut_med = 0.4*(mediana(Lok.tarpRez)) + 0.6*Lok.egzamRez;

        std::cout << std::left << std::setw(20) << Lok.pavarde
        << std::setw(20) << Lok.vardas << std::setw(20) << std::setprecision(2) << std::fixed <<
        galut_med << "\n";
    }
    
}

void outputScan(std::vector<Studentas> &studentai){
    std::sort(studentai.begin(), studentai.end(), 
              [](const Studentas &a, const Studentas &b) {
                  return a.pavarde < b.pavarde;
              });
    
    std::ofstream fw("kursiokai_bendra.txt");

    fw << std::left << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << "\n";
    fw << "---------------------------------------------------------------------------" << "\n";

    for (const Studentas &stud : studentai){
        try {

            if (stud.tarpRez.empty() || stud.tarpRez.size() == 1) {
                throw std::runtime_error("Nepakankamai įvertinimų studentui " + stud.vardas + " " + stud.pavarde + ".");
            }

            double galut_vidurkis = 0.4*(accumulate(stud.tarpRez.begin(), stud.tarpRez.end(), 0.0)/stud.tarpRez.size()) + 0.6*stud.egzamRez;

            std::vector<int> visiRez = stud.tarpRez;
            visiRez.push_back(stud.egzamRez);
            double galut_med =0.4*mediana(visiRez) + 0.6*stud.egzamRez;

            fw << std::left << std::setw(20) << stud.pavarde << std::setw(20) << stud.vardas << std::setw(20) << std::setprecision(2) << std::fixed <<
            galut_vidurkis << std::setw(20) << std::setprecision(2) << std::fixed << galut_med << "\n";
        }

        catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << "\n";
        exit(EXIT_FAILURE);
        }
    }
    std::cout << "Numatytasis failas nuskaitytas ir studentai surikiuoti pagal pavardes." << "\n";
    fw.close();
}

void clean(Studentas &Lok){
    Lok.vardas.clear();
    Lok.pavarde.clear();
    Lok.tarpRez.clear();
    Lok.balai.clear();
}