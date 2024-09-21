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
    std::cout << Lok.vardas << " " << Lok.pavarde << " " << Lok.egzamRez << " " << Lok.tarpRez.size() << std::endl;
}

void clean(Studentas &Lok){
    Lok.vardas.clear();
    Lok.pavarde.clear();
    Lok.tarpRez.clear();
}