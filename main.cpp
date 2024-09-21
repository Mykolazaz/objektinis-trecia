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

    for (int i=0; i<studSk; i++){
        output(studentai.at(i));
    }
    
    output(laikinasStud);

    return 0;
}