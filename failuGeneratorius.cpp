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

void generate(int studGenSk, int ndGenSk){
    std::cout << "Failo generavimas pradėtas." << std::endl;

    std::string failoPav = "info" + std::to_string(studGenSk) + ".txt";
    std::ofstream fw(failoPav);

    studGenSk += 1;
    ndGenSk += 1;

    Timer t;

    fw << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas";
    
    for (int i = 1; i < ndGenSk; i++){
        fw << "ND" << std::setw(2) << std::left << i << " ";
    }

    fw << std::setw(10) << "Egzaminimas" << std::endl;
    
    std::srand(time(0));

    for (int i = 1; i < studGenSk; i++){
        fw << std::left << std::setw(15) << ("Pavarde"+std::to_string(i))
        << std::setw(15) << ("Vardas"+std::to_string(i));
        
        for (int j = 1; j < ndGenSk; j++){
            fw << std::setw(5) << rand() % 10 + 1;    
        }

        fw << std::setw(10) << rand() % 10 + 1 << std::endl;
    }

    fw.close();

    std::cout << std::to_string(studGenSk-1) + " įrašų generavimas: " << t.elapsed() << std::endl;
    std::cout << "Failo generavimas baigtas." << std::endl;
}

void inputScanSort(std::string failoPav, int rusiavKateg) {
    Timer a;

    // Failo nuskaitymo pradžia
    Timer b;

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
    std::cout << "Įrašų nuskaitymas: " << b.elapsed() << std::endl;

    auto sortFunction = [rusiavKateg](const Studentas &a, const Studentas &b) {
        if (rusiavKateg == 0) return a.vardas < b.vardas;
        if (rusiavKateg == 1) return a.pavarde < b.pavarde;
        return a.galutinis > b.galutinis;
    };

    // Visų studentų rikiavimo pradžia
    Timer c;

    std::sort(visiStudentai.begin(), visiStudentai.end(), sortFunction);
    
    // Visų studentų rikiavimo pabaiga
    std::cout << "Įrašų rikiavimas (sort f-ja) mažėjimo tvarka: " << c.elapsed() << std::endl;

    // Studentų dalijimo pradžia
    Timer d;

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
    std::cout << "Įrašų dalijimas į 'protingus' ir 'kvailus': " << d.elapsed() << std::endl;
    
    // "Protingų" studentų rašymo pradžia
    Timer e;

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
    std::cout << "'Protingų' studentų įrašų rašymas: " << e.elapsed() << std::endl;

    // "Kvailų" studentų rašymo pradžia
    Timer f;

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
    std::cout << "'Kvailų' studentų įrašų rašymas: " << f.elapsed() << "\n" << std::endl;

    std::cout << "Bendras veikimo laikas be generavimo: " << a.elapsed() << "\n" << std::endl;
}

void inputScanSortList(std::string failoPav, int rusiavKateg) {
    Timer a;

    // Failo nuskaitymo pradžia
    Timer b;

    failoPav = failoPav + ".txt";
    std::ifstream fr(failoPav);
    std::string eilute;

    std::getline(fr, eilute);

    std::list<Studentas> visiStudentai;

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
    std::cout << "Įrašų nuskaitymas: " << b.elapsed() << std::endl;

    auto sortFunction = [rusiavKateg](const Studentas &a, const Studentas &b) {
        if (rusiavKateg == 0) return a.vardas < b.vardas;
        if (rusiavKateg == 1) return a.pavarde < b.pavarde;
        return a.galutinis > b.galutinis;
    };

    // Visų studentų rikiavimo pradžia
    Timer c;

    std::sort(visiStudentai.begin(), visiStudentai.end(), sortFunction);
    
    // Visų studentų rikiavimo pabaiga
    std::cout << "Įrašų rikiavimas (sort f-ja) mažėjimo tvarka: " << c.elapsed() << std::endl;

    // Studentų dalijimo pradžia
    Timer d;

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
    std::cout << "Įrašų dalijimas į 'protingus' ir 'kvailus': " << d.elapsed() << std::endl;
    
    // "Protingų" studentų rašymo pradžia
    Timer e;

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
    std::cout << "'Protingų' studentų įrašų rašymas: " << e.elapsed() << std::endl;

    // "Kvailų" studentų rašymo pradžia
    Timer f;

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
    std::cout << "'Kvailų' studentų įrašų rašymas: " << f.elapsed() << "\n" << std::endl;

    std::cout << "Bendras veikimo laikas be generavimo: " << a.elapsed() << "\n" << std::endl;
}