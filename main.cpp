#include <iostream>
#include <vector>
#include <iomanip>


struct Studentas{
    std::string vardas;
    std::string pavarde;
    int tarpRezSk;
    std::vector<int> tarpRez;
    int egzamRez;
};


int main(){
    std::vector<Studentas> studentai;
    int studSk;

    std::cout << "Apie kiek studentų pildysite informaciją?:" << std::endl;
    std::cin >> studSk;
    studentai.resize(studSk);

    for (int i=0; i < studSk; i++){
        int input;

        std::cout << "Įveskite studento vardą, pavardę, tarpinių rezultatų sk. ir egz. įvertinimą: " << std::endl;
        std::cin >> studentai[i].vardas >> studentai[i].pavarde >> studentai[i].tarpRezSk >> studentai[i].egzamRez;
        std::cout << "Dabar įveskite šio studento tarpinių įvetinimų rezultatus per 'space' (-1 sustabdo vedimą): " << std::endl;
        
        while(std::cin >> input) { 
            if(input < 0) { 
                break; 
            } 
 
        studentai[i].tarpRez.push_back(input); 
        
        }
    }

    for (int i=0; i < studSk; i++){
        std::cout << studentai[i].vardas << studentai[i].pavarde << studentai[i].egzamRez << studentai[i].tarpRez.size() << std::endl;
    }

    return 0;
}