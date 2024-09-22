#include "lib.h"
#include "studentas.h"

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