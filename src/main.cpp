#include "lib.h"
#include "studentas.h"


int main(){
    std::vector<Studentas> studentai;
    std::list<Studentas> studentaiList;

    int studSk, vidMed, ivedGener, studGenSk, ndGenSk, ivedSkait, rusiavKateg, vektSar, testStrat, arVektorius;
    std::string failoPav;
    
    try{
        std::cout << "Norite įvesti (0), generuoti (1) ar testuoti (2)?: " << "\n";
        std::cin >> ivedGener;
    
        if (!std::cin || (ivedGener != 0 && ivedGener != 1 && ivedGener != 2)){
            throw std::runtime_error("Įrašytas netinkamas simbolis(-iai))!");
        }
    } catch (const std::exception& e) {
        std::cerr << "ERROR:" << e.what() << "\n";
        exit(EXIT_FAILURE);
    }

    // Failo generavimas
    if (ivedGener == 1){
        std::cout << "Kiek studentų ir namų darbų generuoti? (2 skaičiai vienoje eilutėje):" << "\n";
        std::cin >> studGenSk >> ndGenSk;
        generateEntries(studGenSk, ndGenSk);
        exit(EXIT_SUCCESS);

    // Failo testavimas
    } else if (ivedGener == 2){
        std::cout << "Kurią testavimo strategiją norite naudoti?" << "\n"
                  << "1-a strategija (1), 2-a strategija (2), 3-ia strategija (3)" << "\n";
        std::cin >> testStrat;

        std::cout << "Norite naudoti sąrašą (0) ar vektorių (1)?" << "\n";
        std::cin >> arVektorius;

        std::cout << "Kurį failą norite testuoti?" << "\n";
        system("ls *.txt"); //naudoti 'dir' windows platformai

        std::cout << "Įveskite failo pavadinimą (be '.txt'): " << "\n";
        std::cin >> failoPav;

        std::cout << "Norite rušiuoti pagal vardą (0), pavardę (1), galut. balą (2):" << "\n";
        std::cin >> rusiavKateg;

        std::cout << "Failo apdorojimas pradėtas..." << "\n" << "\n";
        inputSplitSort(failoPav, rusiavKateg, arVektorius, testStrat);
        std::cout << "Failo apdorojimas baigtas." << "\n";

        exit(EXIT_SUCCESS);
    }

    // Duomenų įvedimas rankimis
    std::cout << "Duomenis įvesti rankomis (0) ar nuskaityti failą ir išvesti sulygiuotą (1)?:" << "\n";
    std::cin >> ivedSkait;

    if (ivedSkait == 1){
        std::cout << "Kurį failą norite apdoroti?" << "\n";
        system("ls *.txt");
        std::cout << "Įveskite failo pavadinimą (be '.txt'): " << "\n";
        std::cin >> failoPav;

        inputScan(studentai, failoPav);
        outputScan(studentai);
        exit(EXIT_SUCCESS);
    }

    std::cout << "Apie kiek studentų pildysite informaciją?:" << "\n";
    std::cin >> studSk;

    std::cout << "Norite matyti vidurkį (0) ar medianą (1)?" << "\n";
    std::cin >> vidMed;

    std::cout << "Norite informaciją saugoti vektoriuje (0) ar sąraše (1)?:" << "\n";
    std::cin >> vektSar;

    if (vektSar == 0){
        inputManual(studentai, studSk);
    } else {
        inputManualList(studentaiList, studSk);
    }

    if (vidMed == 0){
        std::cout << std::left << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << "\n";
        std::cout << "-------------------------------------------------------" << "\n";
    } else {
        std::cout << std::left << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Med.)" << "\n";
        std::cout << "-------------------------------------------------------" << "\n";
    }
    
    if (vektSar == 0) {
        for (const auto& studentas : studentai) {
            outputManual(studentas, vidMed);
        }
        for (const auto& studentas : studentai) {
            std::cout << "Studento saugojimo vieta atmintyje: " << &studentas << "\n";
        }
    } else {
        for (const auto& i : studentaiList) {
            outputManual(i, vidMed);
        }
        for (const auto& i : studentaiList) {
            std::cout << "Studento saugojimo vieta atmintyje: " << &i << "\n";
        }
    }
    
    return 0;
}