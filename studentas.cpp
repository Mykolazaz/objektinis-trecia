#include "lib.h"
#include "studentas.h"

double mediana(std::vector<double> &v){
    size_t n = v.size();
    std::sort(v.begin(), v.end());
    if (n % 2 == 0) {
        return (v[n/2 - 1] + v[n/2]) / 2.0;
    } else {
        return v[n/2];
    }
}

void input(Studentas &Lok){
    int input;

    std::cout << "Įveskite studento vardą, pavardę, tarpinių rezultatų sk. ir egz. įvertinimą: " << std::endl;
    std::cin >> Lok.vardas >> Lok.pavarde >> Lok.tarpRezSk >> Lok.egzamRez;
    std::cout << "Dabar įveskite šio studento tarpinių įvetinimų rezultatus per 'space' (-1 sustabdo vedimą): " << std::endl;
    
    while(std::cin >> input) { 
        if(input < 0) { 
            break; 
        } 
        Lok.tarpRez.push_back(input); 
    
    }
}

void output(Studentas Lok, int vidMed){
    if(vidMed == 0){
        double vidurkis = (std::accumulate(Lok.tarpRez.begin(), Lok.tarpRez.end(), decltype(Lok.tarpRez)::value_type(0))+Lok.egzamRez)/(Lok.tarpRez.size() + 1);
        std::cout << std::left << std::setw(20) << Lok.pavarde
        << std::setw(20) << Lok.vardas << std::setw(20)<< std::setprecision(2) << std::fixed <<
        vidurkis << std::endl;
    } else {
        std::vector<double> temp = Lok.tarpRez;
        temp.push_back(Lok.egzamRez);
        double med = mediana(temp);

        std::cout << std::left << std::setw(20) << Lok.pavarde
        << std::setw(20) << Lok.vardas << std::setw(20) << std::setprecision(2) << std::fixed <<
        med << std::endl;
    }
    
}

void clean(Studentas &Lok){
    Lok.vardas.clear();
    Lok.pavarde.clear();
    Lok.tarpRez.clear();
}