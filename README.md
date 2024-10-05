### Studentų duomenų apdorojimo programa
- Generuoja studentų informaciją: namų darbai (tarpiniai rezultatai) ir egzamino rezultatai
- Leidžia duomenis įvesti rankomis arba nuskaityti iš failo
- Informacija išvedama į failą sulygiuota ir išrikiuota pagal pavardę
- Atsitiktinai sugeneruoja 1000, 10000, 100000, 1000000, 10000000 studentų duomenų failus, studentus suskirsto į "protingus" ir "kvailus" ir juos išveda į failą atskirai

Panaudotos bibliotekos: iostream, vector, sstream, random, algorithm, fstream, iomanip, stdexception, chrono.

#### Programos veikimo greičio (spartos) analizė (vidurkiai)
##### 1000 įrašų failas
Nuskaitymas: 0.0145543
Rikiavimas (sort f-ja) mažėjimo tvarka: 0.00196567
Dalijimas į 'protingus' ir 'kvailus': 0.00125321
'Protingų' studentų irašų rašymas: 0.00432071
'Kvailų' studentų irašų rašymas: 0.00216279

##### 10000 įrašų failas
Nuskaitymas: 0.0587033
Rikiavimas (sort f-ja) mažėjimo tvarka: 0.00673092
Dalijimas į 'protingus' ir 'kvailus': 0.00584992
'Protingų' studentų irašų rašymas: 0.0172416
'Kvailų' studentų irašų rašymas: 0.0119464

##### 100000 įrašų failas
Nuskaitymas: 0.57386
Rikiavimas (sort f-ja) mažėjimo tvarka: 0.0650226
Dalijimas į 'protingus' ir 'kvailus': 0.0555443
'Protingų' studentų irašų rašymas: 0.163292
'Kvailų' studentų irašų rašymas: 0.116635

##### 1000000 įrašų failas
Nuskaitymas: 6.13895
Rikiavimas (sort f-ja) mažėjimo tvarka: 0.644906
Dalijimas į 'protingus' ir 'kvailus': 0.59008
'Protingų' studentų irašų rašymas: 1.7991
'Kvailų' studentų irašų rašymas: 1.18519

##### 10000000 įrašų failas
Nuskaitymas: 60.3756
Rikiavimas (sort f-ja) mažėjimo tvarka: 6.98117
Dalijimas į 'protingus' ir 'kvailus': 8.67058
'Protingų' studentų irašų rašymas: 17.9269
'Kvailų' studentų irašų rašymas: 12.5671