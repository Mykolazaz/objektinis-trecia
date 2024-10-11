### Studentų duomenų apdorojimo programa
- Generuoja studentų informaciją: namų darbai (tarpiniai rezultatai) ir egzamino rezultatai
- Leidžia duomenis įvesti rankomis arba nuskaityti iš failo
- Informacija išvedama į failą sulygiuota ir išrikiuota pagal pavardę
- Atsitiktinai sugeneruoja 1000, 10000, 100000, 1000000, 10000000 studentų duomenų failus, studentus suskirsto į "protingus" ir "kvailus" ir juos išveda į failą atskirai

Panaudotos bibliotekos: iostream, vector, sstream, random, algorithm, fstream, iomanip, stdexception, chrono.

#### Programos veikimo greičio (spartos) analizė (vidurkiai)

##### 1000 įrašų failas
- Generavimas: 0.0121934
- Nuskaitymas: 0.006234
- Rikiavimas (sort f-ja) mažėjimo tvarka: 0.00016
- Dalijimas į 'protingus' ir 'kvailus': 0.000211708
- 'Protingų' studentų įrašų rašymas: 0.00425054
- 'Kvailų' studentų įrašų rašymas: 0.00271296

##### 10000 įrašų failas
- Generavimas: 0.095239
- Nuskaitymas: 0.0371276
- Rikiavimas (sort f-ja) mažėjimo tvarka: 0.000987667
- Dalijimas į 'protingus' ir 'kvailus': 0.00150442
- 'Protingų' studentų įrašų rašymas: 0.0243142
- 'Kvailų' studentų įrašų rašymas: 0.017445

##### 100000 įrašų failas
- Generavimas: 0.613153
- Nuskaitymas: 0.362049
- Rikiavimas (sort f-ja) mažėjimo tvarka: 0.00969379
- Dalijimas į 'protingus' ir 'kvailus': 0.0136939
- 'Protingų' studentų įrašų rašymas: 0.239303
- 'Kvailų' studentų įrašų rašymas: 0.167813

##### 1000000 įrašų failas
- Generavimas: 6.09209
- Nuskaitymas: 3.58912
- Rikiavimas (sort f-ja) mažėjimo tvarka: 0.0973582
- Dalijimas į 'protingus' ir 'kvailus': 0.14392
- 'Protingų' studentų įrašų rašymas: 2.36107
- 'Kvailų' studentų įrašų rašymas: 1.66743

##### 10000000 įrašų failas
- Generavimas: 62.4118
- Nuskaitymas: 39.7028
- Rikiavimas (sort f-ja) mažėjimo tvarka: 1.78239
- Dalijimas į 'protingus' ir 'kvailus': 9.78603
- 'Protingų' studentų įrašų rašymas: 27.1772
- 'Kvailų' studentų įrašų rašymas: 18.269