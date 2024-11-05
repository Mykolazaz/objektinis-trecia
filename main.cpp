#include "lib.h"
#include "studentas.h"


int main(){
    std::vector<Studentas> studentai;
    std::list<Studentas> studentaiList;
    Studentas laikinasStud;

    int studSk, vidMed, ivedGener, studGenSk, ndGenSk, ivedSkait, rusiavKateg, vektSar, testStrat;
    std::string failoPav;
    
    try{
        std::cout << "Norite įvesti (0), generuoti (1) ar testuoti (2)?: " << std::endl;
        std::cin >> ivedGener;
    
        if (!std::cin || (ivedGener != 0 && ivedGener != 1 && ivedGener != 2)){
            throw std::runtime_error("Įrašytas netinkamas simbolis(-iai))!");
        }
    } catch (const std::exception& e) {
        std::cerr << "ERROR:" << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    // Failo generavimas
    if (ivedGener == 1){
        std::cout << "Kiek studentų ir namų darbų generuoti? (2 skaičiai vienoje eilutėje):" << std::endl;
        std::cin >> studGenSk >> ndGenSk;
        generateInfo(studGenSk, ndGenSk);
        exit(EXIT_SUCCESS);

    // Failo testavimas
    } else if (ivedGener == 2){
        std::cout << "Kurią testavimo strategiją norite naudoti?" << std::endl;
        std::cout << "1-a strategija (1), 2-a strategija (2), 3-ia strategija (3)" << std::endl;
        std::cin >> testStrat;

        std::cout << "Kurį failą norite testuoti?" << std::endl;
        system("ls *.txt"); //naudoti 'dir' windows platformai

        std::cout << "Įveskite failo pavadinimą (be '.txt'): " << std::endl;
        std::cin >> failoPav;

        std::cout << "Norite rušiuoti pagal vardą (0), pavardę (1), galut. balą (2):" << std::endl;
        std::cin >> rusiavKateg;

        std::cout << "Failo apdorojimas pradėtas..." << "\n" << std::endl;
        inputSplitSort(failoPav, rusiavKateg, true, testStrat);
        inputSplitSort(failoPav, rusiavKateg, false, testStrat);
        
        std::cout << "Failo apdorojimas baigtas." << std::endl;
        exit(EXIT_SUCCESS);
    }

    // Duomenų įvedimas rankimis
    std::cout << "Duomenis įvesti rankomis (0) ar nuskaityti failą ir išvesti sulygiuotą (1)?:" << std::endl;
    std::cin >> ivedSkait;

    if (ivedSkait == 1){
        inputScan(studentai);
        outputScan(studentai);
        exit(EXIT_SUCCESS);
    }

    std::cout << "Apie kiek studentų pildysite informaciją?:" << std::endl;
    std::cin >> studSk;

    std::cout << "Norite matyti vidurkį (0) ar medianą (1)?" << std::endl;
    std::cin >> vidMed;

    std::cout << "Norite informaciją saugoti vektoriuje (0) ar sąraše (1)?:" << std::endl;
    std::cin >> vektSar;

    if (vektSar == 0){
        inputManual(studentai, studSk, vidMed);
    } else {
        inputManualList(studentaiList, studSk, vidMed);
    }

    if (vidMed == 0){
        std::cout << std::left << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
    } else {
        std::cout << std::left << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Med.)" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
    }
    
    if (vektSar == 0){
        for (int i=0; i<studSk; i++){
            outputManual(studentai.at(i), vidMed);
        }
    } else {
        for (auto& i : studentaiList){
            outputManual(i, vidMed);
        }
    }

    if (vektSar == 0){
        for (int i=0; i<studSk; i++){
            std::cout << "Studento saugojimo vieta atmintyje: " << &studentai.at(i) << std::endl;
        }
    } else {
        for (auto& i : studentaiList){
            std::cout << "Studento saugojimo vieta atmintyje: " << &i << std::endl;
        }
    }
    
    return 0;
}