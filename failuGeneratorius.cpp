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

// naudotojas turi pasirinkti pagal ką reikia rušiuoti: vardas, pavarde, balas
void inputScanSort(int studGenSk, int rusiavKateg) {
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff;

    // Failų nuskaitymo laiko fiksavimo pradžia
    start = std::chrono::high_resolution_clock::now();

    std::string failoPavadinimas = "informacija" + std::to_string(studGenSk) + ".txt";
    std::ifstream fr(failoPavadinimas);
    std::string eilute;

    std::getline(fr, eilute);

    std::vector<Studentas> visiStudentai;

    while (std::getline(fr, eilute)) {
        std::istringstream iss(eilute);
        Studentas Lok;

        iss >> Lok.pavarde >> Lok.vardas;

        int balas;
        while (iss >> balas) {
            Lok.balai.push_back(balas);
        }

        if (!Lok.balai.empty()) {
            Lok.egzamRez = Lok.balai.back();
            Lok.balai.pop_back();
            Lok.tarpRez = Lok.balai;
        }

        double galut_vidurkis = 0.4*(accumulate(Lok.tarpRez.begin(), Lok.tarpRez.end(), 0.0)/Lok.tarpRez.size()) + 0.6*Lok.egzamRez;
        Lok.galutinis = galut_vidurkis;

        visiStudentai.push_back(Lok);
    }
    fr.close();

    // Failų nuskaitymo laiko fiksavimo pabaiga
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << std::to_string(studGenSk) + " įrašų nuskaitymo laikas: " << diff.count() << std::endl;

    // Failų rikiavimo laiko fiksavimo pradžia
    start = std::chrono::high_resolution_clock::now();

    if (rusiavKateg == 0) {
        std::sort(visiStudentai.begin(), visiStudentai.end(), 
                  [](const Studentas &a, const Studentas &b) { return a.vardas < b.vardas; });
    } else if (rusiavKateg == 1) {
        std::sort(visiStudentai.begin(), visiStudentai.end(), 
                  [](const Studentas &a, const Studentas &b) { return a.pavarde < b.pavarde; });
    } else if (rusiavKateg == 2) {
        std::sort(visiStudentai.begin(), visiStudentai.end(), 
                  [](const Studentas &a, const Studentas &b) { return a.galutinis > b.galutinis; });
    }

    // Failų rikiavimo laiko fiksavimo pabaiga
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << std::to_string(studGenSk) + " įrašų rikiavimo mažėjimo tvarka laikas: " << diff.count() << std::endl;

    // Failų rašymo laiko fiksavimo pradžia
    start = std::chrono::high_resolution_clock::now();

    std::string failasProtingi = "protingi" + std::to_string(studGenSk) + ".txt";
    std::ofstream fwProtingi(failasProtingi);
    
    std::string failasKvaili = "kvaili" + std::to_string(studGenSk) + ".txt";
    std::ofstream fwKvaili(failasKvaili);

    for (const auto &Lok : visiStudentai) {
        if (Lok.galutinis >= 5.0){
            fwProtingi << std::left << std::setw(20) << Lok.pavarde << std::setw(20) << Lok.vardas << std::setw(20) << std::setprecision(2) << std::fixed <<
            Lok.galutinis << std::endl;
        } else {
            fwKvaili << std::left << std::setw(20) << Lok.pavarde << std::setw(20) << Lok.vardas << std::setw(20) << std::setprecision(2) << std::fixed <<
            Lok.galutinis << std::endl;
        }
    }

    fwProtingi.close();
    fwKvaili.close();

    // Failų rašymo laiko fiksavimo pabaiga
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << std::to_string(studGenSk) + " įrašų išvedimo į atskirus failus laikas: " << diff.count() << std::endl;
}


void generateAll(int rusiavKateg){
    // std::cout << "Failas su 1000 studentų generuojamas..." << std::endl;
    generate(1000, 7);
    inputScanSort(1000, rusiavKateg); // skaičius nurodo, kurį failą reikia atidaryti
    // std::cout << "Failas su 1000 studentų sugeneruotas ir išskirstytas pagal balus." << std::endl;

    // std::cout << "Failas su 10000 studentų generuojamas..." << std::endl;
    generate(10000, 7);
    inputScanSort(10000, rusiavKateg);
    // std::cout << "Failas su 10000 studentų sugeneruotas ir išskirstytas pagal balus." << std::endl;

    // std::cout << "Failas su 100000 studentų generuojamas..." << std::endl;
    generate(100000, 7);
    inputScanSort(100000, rusiavKateg);
    // std::cout << "Failas su 100000 studentų sugeneruotas ir išskirstytas pagal balus." << std::endl;

    // std::cout << "Failas su 1000000 studentų generuojamas..." << std::endl;
    generate(1000000, 7);
    inputScanSort(1000000, rusiavKateg);
    // std::cout << "Failas su 1000000 studentų sugeneruotas ir išskirstytas pagal balus." << std::endl;

    // std::cout << "Failas su 10000000 studentų generuojamas..." << std::endl;
    generate(10000000, 7);
    inputScanSort(10000000, rusiavKateg);
    // std::cout << "Failas su 10000000 studentų sugeneruotas ir išskirstytas pagal balus." << std::endl;

    std::cout << "Šabloninio generavimo ir išskirstymo darbas baigtas." << std::endl;
}