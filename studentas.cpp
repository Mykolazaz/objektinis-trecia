#include "lib.h"
#include "studentas.h"

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

void output(Studentas Lok){
    std::cout << std::left << std::setw(20) << Lok.pavarde << std::setw(20) << Lok.vardas << std::setw(20) << std::setprecision(3) << (std::accumulate(Lok.tarpRez.begin(), Lok.tarpRez.end(), decltype(Lok.tarpRez)::value_type(0))+Lok.egzamRez)/(Lok.tarpRez.size() + 1) << std::endl;
}

void clean(Studentas &Lok){
    Lok.vardas.clear();
    Lok.pavarde.clear();
    Lok.tarpRez.clear();
}