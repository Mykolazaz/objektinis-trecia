#include "lib.h"
#include "studentas.h"

void generate(int studGenSk, int ndGenSk){
    std::string failoPavadinimas = "informacija" + std::to_string(studGenSk) + ".txt";
    std::ofstream fw(failoPavadinimas);

    studGenSk += 1;
    ndGenSk += 1;

    fw << std::left << std::setw(15) << "Pavarde"
    << std::setw(15) << "Vardas";

    for (int i = 1; i < ndGenSk; i++){
        fw << "ND" << std::setw(2) << std::left << i << " ";
    }

    fw << std::setw(10) << "Egzaminimas" << std::endl;
    
    for (int i = 1; i < studGenSk; i++){
        fw << std::left << std::setw(15) << ("Pavarde"+std::to_string(i))
        << std::setw(15) << ("Vardas"+std::to_string(i));
        
        for (int j = 1; j < ndGenSk; j++){
            fw << std::setw(5) << rand() % 10 + 1;    
        }

        fw << std::setw(10) << rand() % 10 + 1 << std::endl;
    }

    fw.close();
}

void generateAll(int ndGenSk){
    generate(1000, ndGenSk);
    std::cout << "Failas su 1000 studentų sugeneruotas." << std::endl;
    generate(10000, ndGenSk);
    std::cout << "Failas su 10000 studentų sugeneruotas." << std::endl;
    generate(100000, ndGenSk);
    std::cout << "Failas su 100000 studentų sugeneruotas." << std::endl;
    generate(1000000, ndGenSk);
    std::cout << "Failas su 1000000 studentų sugeneruotas." << std::endl;
    generate(10000000, ndGenSk);
    std::cout << "Failas su 10000000 studentų sugeneruotas." << std::endl;
    std::cout << "Šabloninio generavimo darbas baigtas." << std::endl;
}