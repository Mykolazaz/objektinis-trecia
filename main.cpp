#include "lib.h"
#include "studentas.h"


int main(){
    std::vector<Studentas> studentai;
    Studentas laikinasStud;

    int studSk, vidMed, ivedGener, studGenSk, ndGenSk, ivedSkait;
    
    try{
        std::cout << "Norite įvesti (0) ar generuoti (1)?: " << std::endl;
        std::cin >> ivedGener;
    
        if (ivedGener != 0 && ivedGener != 1){
            throw std::runtime_error("Įrašytas netinkamas simbolis!");
        }
    }
    catch (const std::exception& e) {
        std::cerr << "ERROR:" << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    if (ivedGener == 1){
        std::cout << "Kiek studentų ir namų darbų generuoti? (2 skaičiai vienoje eilutėje):" << std::endl;
        std::cin >> studGenSk >> ndGenSk;
        generate(studGenSk, ndGenSk);
        exit(EXIT_SUCCESS);
    }

    std::cout << "Duomenis įvesti rankomis (0) ar nuskaityti failą ir išvesti sulygiuotą (1)?:" << std::endl;
    std::cin >> ivedSkait;

    if (ivedSkait == 1){
        inputScan(studentai);

        std::cout << std::left << std::setw(20) << "Pavardė" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << std::endl;
        std::cout << "---------------------------------------------------------------------------" << std::endl;

        outputScan(studentai);

        exit(EXIT_SUCCESS);
    }

    std::cout << "Apie kiek studentų pildysite informaciją?:" << std::endl;
    std::cin >> studSk;
    std::cout << "Norite matyti vidurkį (0) ar medianą (1)?" << std::endl;
    std::cin >> vidMed;

    for (int i=0; i<studSk; i++){
        inputManual(laikinasStud);
        studentai.push_back(laikinasStud);
        clean(laikinasStud);
    }

    if (vidMed == 0){
        std::cout << std::left << std::setw(21) << "Pavardė" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
    } else {
        std::cout << std::left << std::setw(21) << "Pavardė" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Med.)" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
    }
    
    for (int i=0; i<studSk; i++){
        outputManual(studentai.at(i), vidMed);
    }
    
    return 0;
}