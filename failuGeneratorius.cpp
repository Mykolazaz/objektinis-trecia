#include "lib.h"
#include "studentas.h"

void generate(int studGenSk, int ndGenSk){
    std::string failoPavadinimas = "informacija" + std::to_string(studGenSk) + ".txt";
    std::ofstream fw(failoPavadinimas);

    studGenSk += 1;
    ndGenSk += 1;

    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff;

    // Failo nuskaitymo pradžia
    start = std::chrono::high_resolution_clock::now();

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

    // Failo nuskaitymo pabaiga
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << std::to_string(studGenSk-1) + " įrašų generavimas: " << diff.count() << std::endl;
}

// naudotojas turi pasirinkti pagal ką reikia rušiuoti: vardas, pavarde, balas
void inputScanSort(int studGenSk, int rusiavKateg) {
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff;

    // Failo nuskaitymo pradžia
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

    // Failo nuskaitymo pabaiga
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << std::to_string(studGenSk) + " įrašų nuskaitymas: " << diff.count() << std::endl;


    auto sortFunction = [rusiavKateg](const Studentas &a, const Studentas &b) {
        if (rusiavKateg == 0) return a.vardas < b.vardas;
        if (rusiavKateg == 1) return a.pavarde < b.pavarde;
        return a.galutinis > b.galutinis;
    };

    // Visų studentų rikiavimo pradžia
    start = std::chrono::high_resolution_clock::now();
    
    std::sort(visiStudentai.begin(), visiStudentai.end(), sortFunction);
    
    // Visų studentų rikiavimo pabaiga
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << std::to_string(studGenSk) + " įrašų rikiavimas (sort f-ja) mažėjimo tvarka: " << diff.count() << std::endl;


    // Studentų dalijimo pradžia
    start = std::chrono::high_resolution_clock::now();

    std::vector<Studentas> protingi, kvaili;
    for (const auto &student : visiStudentai) {
        if (student.galutinis >= 5.0) {
            protingi.push_back(student);
        } else {
            kvaili.push_back(student);
        }
    }

    // Studentų dalijimo pabaiga
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << std::to_string(studGenSk) + " įrašų dalijimas į 'protingus' ir 'kvailus': " << diff.count() << std::endl;

    
    // "Protingų" studentų rašymo pradžia
    start = std::chrono::high_resolution_clock::now();

    std::string failasProtingi = "protingi" + std::to_string(studGenSk) + ".txt";
    std::ofstream fwProtingi(failasProtingi);
    
    for (const auto &student : protingi) {
        fwProtingi << std::left << std::setw(20) << student.pavarde << std::setw(20) << student.vardas 
                   << std::setw(20) << std::setprecision(2) << std::fixed << student.galutinis << std::endl;
    }

    fwProtingi.close();

    // "Protingų" studentų rašymo pabaiga
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "'Protingų' studentų įrašų rašymas: " << diff.count() << std::endl;

    // "Kvailų" studentų rašymo pradžia
    start = std::chrono::high_resolution_clock::now();

    std::string failasKvaili = "kvaili" + std::to_string(studGenSk) + ".txt";
    std::ofstream fwKvaili(failasKvaili);

    for (const auto &student : kvaili) {
        fwKvaili << std::left << std::setw(20) << student.pavarde << std::setw(20) << student.vardas 
                 << std::setw(20) << std::setprecision(2) << std::fixed << student.galutinis << std::endl;
    }

    fwKvaili.close();

    // "Kvailų" studentų rašymo pabaiga
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "'Kvailų' studentų įrašų rašymas: " << diff.count() << "\n" << std::endl;
}


void generateAll(int rusiavKateg){
    generate(1000, 15);
    inputScanSort(1000, rusiavKateg); // skaičius nurodo, kurį failą reikia atidaryti, t.y. informacija(1000).txt

    generate(10000, 15);
    inputScanSort(10000, rusiavKateg);

    generate(100000, 15);
    inputScanSort(100000, rusiavKateg);

    generate(1000000, 15);
    inputScanSort(1000000, rusiavKateg);

    generate(10000000, 15);
    inputScanSort(10000000, rusiavKateg);
}