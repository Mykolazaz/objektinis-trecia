#include "lib.h"
#include "studentas.h"


int main(){
    std::vector<Studentas> studentai;
    Studentas laikinasStud;

    int studSk;

    std::cout << "Apie kiek studentų pildysite informaciją?:" << std::endl;
    std::cin >> studSk;

    for (int i=0; i<studSk; i++){
        input(laikinasStud);
        studentai.push_back(laikinasStud);
        clean(laikinasStud);
    }

    std::cout << std::left << std::setw(20) << "Pavardė" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    for (int i=0; i<studSk; i++){
        output(studentai.at(i));
    }
    

    return 0;
}