### Studentų duomenų apdorojimo programa
- Generuoja studentų informaciją: namų darbai (tarpiniai rezultatai) ir egzamino rezultatai
- Leidžia duomenis įvesti rankomis arba nuskaityti iš failo
- Informacija išvedama į failą sulygiuota ir išrikiuota pagal pavardę
- Atsitiktinai sugeneruoja 1000, 10000, 100000, 1000000, 10000000 studentų duomenų failus, studentus suskirsto į "protingus" ir "kvailus" ir juos išveda į failą atskirai

Panaudotos bibliotekos: iostream, vector, sstream, random, algorithm, fstream, iomanip, stdexception, chrono.

#### Programos veikimo greičio (spartos) analizė (vidurkiai)

##### 1000 įrašų failas
- Generavimas: 0.0125079
- Nuskaitymas: 0.00622196
- Rikiavimas (sort f-ja) mažėjimo tvarka: 0.000161875
- Dalijimas į 'protingus' ir 'kvailus': 0.000255541
- 'Protingų' studentų įrašų rašymas: 0.00435612
- 'Kvailų' studentų įrašų rašymas: 0.00312658
- Bendras veikimo laikas be generavimo: 0.0141221

##### 10000 įrašų failas
- Generavimas: 0.0641175
- Nuskaitymas: 0.0362948
- Rikiavimas (sort f-ja) mažėjimo tvarka: 0.00099025
- Dalijimas į 'protingus' ir 'kvailus': 0.00147125
- 'Protingų' studentų įrašų rašymas: 0.0318718
- 'Kvailų' studentų įrašų rašymas: 0.0171221
- Bendras veikimo laikas be generavimo: 0.0877502

##### 100000 įrašų failas
- Generavimas: 0.606544
- Nuskaitymas: 0.359194
- Rikiavimas (sort f-ja) mažėjimo tvarka: 0.0100091
- Dalijimas į 'protingus' ir 'kvailus': 0.0142796
- 'Protingų' studentų įrašų rašymas: 0.240313
- 'Kvailų' studentų įrašų rašymas: 0.172792
- Bendras veikimo laikas be generavimo: 0.796588

##### 1000000 įrašų failas
- Generavimas: 6.25748
- Nuskaitymas: 3.62752
- Rikiavimas (sort f-ja) mažėjimo tvarka: 0.110206
- Dalijimas į 'protingus' ir 'kvailus': 0.205448
- 'Protingų' studentų įrašų rašymas: 2.45075
- 'Kvailų' studentų įrašų rašymas: 1.74791
- Bendras veikimo laikas be generavimo: 8.14183

##### 10000000 įrašų failas
- Generavimas: 63.4451
- Nuskaitymas: 36.9167
- Rikiavimas (sort f-ja) mažėjimo tvarka: 1.79614
- Dalijimas į 'protingus' ir 'kvailus': 11.6688
- 'Protingų' studentų įrašų rašymas: 25.9685
- 'Kvailų' studentų įrašų rašymas: 18.2166
- Bendras veikimo laikas be generavimo: 94.5667