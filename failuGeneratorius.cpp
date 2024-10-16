#include "lib.h"
#include "studentas.h"

class Timer {
  private:
    using hrClock = std::chrono::high_resolution_clock;
    using durationDouble = std::chrono::duration<double>;
    std::chrono::time_point<hrClock> start;
  public:
    Timer() : start{ hrClock::now() } {}
    void reset() {
      start = hrClock::now();
    }
    double elapsed() const {
      return durationDouble (hrClock::now() - start).count();
    }
};

void generateInfo(int studGenSk, int ndGenSk){
    std::cout << "Failo generavimas pradėtas." << std::endl;

    std::string failoPav = "info" + std::to_string(studGenSk) + ".txt";
    std::ofstream fw(failoPav, std::ios::binary);

    studGenSk += 1;
    ndGenSk += 1;

    Timer generLaikas;

    std::stringstream buffer;

    buffer << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas";
    
    for (int i = 1; i < ndGenSk; i++){
        buffer << "ND" << std::setw(2) << std::left << i << " ";
    }

    buffer << std::setw(10) << "Egzaminimas" << std::endl;
    
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 10);

    std::string pavarde, vardas;
    pavarde.reserve(15);
    vardas.reserve(15);

    for (int i = 1; i < studGenSk; i++){
        buffer << std::left << std::setw(15) << ("Pavarde"+std::to_string(i))
        << std::setw(15) << ("Vardas"+std::to_string(i));
        
        for (int j = 1; j < ndGenSk; j++){
            buffer << std::setw(5) << dist(mt);    
        }

        buffer << std::setw(10) << dist(mt) << std::endl;

        if (buffer.tellp() > 64 * 1024 * 1024) {
            fw << buffer.rdbuf();
            buffer.str("");
            buffer.clear();
        }
    }

    fw << buffer.rdbuf();
    
    fw.close();

    std::cout << std::to_string(studGenSk-1) + " įrašų generavimas: " << generLaikas.elapsed() << std::endl;
    std::cout << "Failo generavimas baigtas." << std::endl;
}

void inputSplitSort(std::string failoPav, int rusiavKateg) {
    Timer bendrLaikas;

    // Failo nuskaitymo pradžia
    Timer uzdLaikas;

    failoPav = failoPav + ".txt";
    std::ifstream fr(failoPav);
    std::string eilute;

    std::getline(fr, eilute);

    std::vector<Studentas> visiStudentai;

    visiStudentai.reserve(1000000);

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
    std::cout << "Įrašų nuskaitymas: " << uzdLaikas.elapsed() << std::endl;

    auto sortFunction = [rusiavKateg](const Studentas &a, const Studentas &b) {
        if (rusiavKateg == 0) return a.vardas < b.vardas;
        if (rusiavKateg == 1) return a.pavarde < b.pavarde;
        return a.galutinis > b.galutinis;
    };

    // Visų studentų rikiavimo pradžia
    uzdLaikas.reset();

    std::sort(visiStudentai.begin(), visiStudentai.end(), sortFunction);
    
    // Visų studentų rikiavimo pabaiga
    std::cout << "Įrašų rikiavimas (sort f-ja) mažėjimo tvarka: " << uzdLaikas.elapsed() << std::endl;

    // Studentų dalijimo pradžia
    uzdLaikas.reset();

    std::vector<Studentas> protingi, kvaili;

    for (const auto &student : visiStudentai) {
        if (student.galutinis >= 5.0) {
            protingi.push_back(student);
        } else {
            kvaili.push_back(student);
        }
    }
    visiStudentai.clear();

    // Studentų dalijimo pabaiga
    std::cout << "Įrašų dalijimas į 'protingus' ir 'kvailus': " << uzdLaikas.elapsed() << std::endl;
    
    // "Protingų" studentų rašymo pradžia
    uzdLaikas.reset();

    std::string failasProtingi = "protingi.txt";
    std::ofstream fwProtingi(failasProtingi);
    
    fwProtingi << std::left << std::setw(20) << "Pavarde"
    << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (vid.)" << std::endl;
    fwProtingi << "-------------------------------------------------------" << std::endl;

    for (const auto &student : protingi) {
        fwProtingi << std::left << std::setw(20) << student.pavarde << std::setw(20) << student.vardas 
                   << std::setw(20) << std::setprecision(2) << std::fixed << student.galutinis << std::endl;
    }

    fwProtingi.close();
    protingi.clear();

    // "Protingų" studentų rašymo pabaiga
    std::cout << "'Protingų' studentų įrašų rašymas: " << uzdLaikas.elapsed() << std::endl;

    // "Kvailų" studentų rašymo pradžia
    uzdLaikas.reset();

    std::string failasKvaili = "kvaili.txt";
    std::ofstream fwKvaili(failasKvaili);

    fwKvaili << std::left << std::setw(20) << "Pavarde"
    << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (vid.)" << std::endl;;
    fwKvaili << "-------------------------------------------------------" << std::endl;

    for (const auto &student : kvaili) {
        fwKvaili << std::left << std::setw(20) << student.pavarde << std::setw(20) << student.vardas 
                 << std::setw(20) << std::setprecision(2) << std::fixed << student.galutinis << std::endl;
    }

    fwKvaili.close();
    kvaili.clear();

    // "Kvailų" studentų rašymo pabaiga
    std::cout << "'Kvailų' studentų įrašų rašymas: " << uzdLaikas.elapsed() << "\n" << std::endl;

    std::cout << "Bendras veikimo laikas be generavimo: " << bendrLaikas.elapsed() << "\n" << std::endl;
}

void inputSplitSortList(std::string failoPav, int rusiavKateg) {
    Timer bendrLaikas;

    // Failo nuskaitymo pradžia
    Timer uzdLaikas;

    failoPav = failoPav + ".txt";
    std::ifstream fr(failoPav);
    std::string eilute;

    std::getline(fr, eilute);

    std::list<Studentas> visiStudentaiList;

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

        visiStudentaiList.push_back(Lok);
    }
    fr.close();

    // Failo nuskaitymo pabaiga
    std::cout << "Įrašų nuskaitymas: " << uzdLaikas.elapsed() << std::endl;

    auto sortFunction = [rusiavKateg](const Studentas &a, const Studentas &b) {
        if (rusiavKateg == 0) return a.vardas < b.vardas;
        if (rusiavKateg == 1) return a.pavarde < b.pavarde;
        return a.galutinis > b.galutinis;
    };

    // Visų studentų rikiavimo pradžia
    uzdLaikas.reset();

    visiStudentaiList.sort(sortFunction);
    
    // Visų studentų rikiavimo pabaiga
    std::cout << "Įrašų rikiavimas (sort f-ja) mažėjimo tvarka: " << uzdLaikas.elapsed() << std::endl;

    // Studentų dalijimo pradžia
    uzdLaikas.reset();

    std::list<Studentas> protingiList, kvailiList;

    for (const auto &student : visiStudentaiList) {
        if (student.galutinis >= 5.0) {
            protingiList.push_back(student);
        } else {
            kvailiList.push_back(student);
        }
    }
    visiStudentaiList.clear();

    // Studentų dalijimo pabaiga
    std::cout << "Įrašų dalijimas į 'protingus' ir 'kvailus': " << uzdLaikas.elapsed() << std::endl;
    
    // "Protingų" studentų rašymo pradžia
    uzdLaikas.reset();

    std::string failasProtingi = "protingi.txt";
    std::ofstream fwProtingi(failasProtingi);
    
    fwProtingi << std::left << std::setw(20) << "Pavarde"
    << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (vid.)" << std::endl;
    fwProtingi << "-------------------------------------------------------" << std::endl;

    for (const auto &student : protingiList) {
        fwProtingi << std::left << std::setw(20) << student.pavarde << std::setw(20) << student.vardas 
                   << std::setw(20) << std::setprecision(2) << std::fixed << student.galutinis << std::endl;
    }

    fwProtingi.close();
    protingiList.clear(); 

    // "Protingų" studentų rašymo pabaiga
    std::cout << "'Protingų' studentų įrašų rašymas: " << uzdLaikas.elapsed() << std::endl;

    // "Kvailų" studentų rašymo pradžia
    uzdLaikas.reset();

    std::string failasKvaili = "kvaili.txt";
    std::ofstream fwKvaili(failasKvaili);

    fwKvaili << std::left << std::setw(20) << "Pavarde"
    << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (vid.)" << std::endl;;
    fwKvaili << "-------------------------------------------------------" << std::endl;

    for (const auto &student : kvailiList) {
        fwKvaili << std::left << std::setw(20) << student.pavarde << std::setw(20) << student.vardas 
                 << std::setw(20) << std::setprecision(2) << std::fixed << student.galutinis << std::endl;
    }

    fwKvaili.close();
    kvailiList.clear();

    // "Kvailų" studentų rašymo pabaiga
    std::cout << "'Kvailų' studentų įrašų rašymas: " << uzdLaikas.elapsed() << "\n" << std::endl;

    std::cout << "Bendras veikimo laikas be generavimo: " << bendrLaikas.elapsed() << "\n" << std::endl;
}