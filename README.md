## Studentų duomenų apdorojimo programa
- Generuoja studentų informaciją: namų darbai (tarpiniai rezultatai) ir egzamino rezultatai
- Leidžia duomenis įvesti rankomis arba nuskaityti iš failo
- Informacija išvedama į failą sulygiuota ir išrikiuota pagal pavardę
- Studentus suskirsto į "protingus" ir "kvailus" ir juos išveda į failą atskirai

Panaudotos bibliotekos: iostream, vector, sstream, random, algorithm, fstream, iomanip, stdexception, chrono, list.

### Programos veikimo greičio (spartos) analizė (vidurkiai)
Testavimo įranga:
- CPU: Apple M1
- RAM: 8 GB unified memory
- SSD: 256 GB ~2700 MB/s


### Testavimas su std::vector
##### 1000 įrašų failas
- Generavimas: 0.012351
- Nuskaitymas: 0.00770167
- Rikiavimas (sort f-ja) mažėjimo tvarka: 0.000159834
- Dalijimas į 'protingus' ir 'kvailus': 0.000364667
- 'Protingų' studentų įrašų rašymas: 0.00670146
- 'Kvailų' studentų įrašų rašymas: 0.00420112
- Bendras veikimo laikas be generavimo: 0.0191918

##### 10000 įrašų failas
- Generavimas: 0.0742816
- Nuskaitymas: 0.0493761
- Rikiavimas (sort f-ja) mažėjimo tvarka: 0.00102404
- Dalijimas į 'protingus' ir 'kvailus': 0.00242704
- 'Protingų' studentų įrašų rašymas: 0.0254398
- 'Kvailų' studentų įrašų rašymas: 0.0225923
- Bendras veikimo laikas be generavimo: 0.100913

##### 100000 įrašų failas
- Generavimas: 0.63824
- Nuskaitymas: 0.369705
- Rikiavimas (sort f-ja) mažėjimo tvarka: 0.0100943
- Dalijimas į 'protingus' ir 'kvailus': 0.0367114
- 'Protingų' studentų įrašų rašymas: 0.261315
- 'Kvailų' studentų įrašų rašymas: 0.175635
- Bendras veikimo laikas be generavimo: 0.853551

##### 1000000 įrašų failas
- Generavimas: 6.16426
- Nuskaitymas: 3.60744
- Rikiavimas (sort f-ja) mažėjimo tvarka: 0.100711
- Dalijimas į 'protingus' ir 'kvailus': 0.509795
- 'Protingų' studentų įrašų rašymas: 2.46102
- 'Kvailų' studentų įrašų rašymas: 1.75278
- Bendras veikimo laikas be generavimo: 8.43186

##### 10000000 įrašų failas
- Generavimas: 64.2023
- Nuskaitymas: 38.1499
- Rikiavimas (sort f-ja) mažėjimo tvarka: 1.78069
- Dalijimas į 'protingus' ir 'kvailus': 17.2195
- 'Protingų' studentų įrašų rašymas: 28.2085
- 'Kvailų' studentų įrašų rašymas: 18.8737
- Bendras veikimo laikas be generavimo: 104.232