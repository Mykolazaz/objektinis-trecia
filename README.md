### Studentų duomenų apdorojimo programa
- Generuoja studentų informaciją: namų darbai (tarpiniai rezultatai) ir egzamino rezultatai
- Leidžia duomenis įvesti rankomis arba nuskaityti iš failo
- Informacija išvedama į failą sulygiuota ir išrikiuota pagal pavardę
- Atsitiktinai sugeneruoja 1000, 10000, 100000, 1000000, 10000000 studentų duomenų failus, studentus suskirsto į "protingus" ir "kvailus" ir juos išveda į failą atskirai

Panaudotos bibliotekos: iostream, vector, sstream, random, algorithm, fstream, iomanip, stdexception, chrono.

#### Programos veikimo greičio (spartos) analizė (vidurkiai)

1000 įrašų generavimas: 0.0142855
1000 įrašų nuskaitymas: 0.0190097
1000 įrašų rikiavimas (sort f-ja) mažėjimo tvarka: 0.00199533
1000 įrašų dalijimas į 'protingus' ir 'kvailus': 0.00109792
'Protingų' studentų įrašų rašymas: 0.00355567
'Kvailų' studentų įrašų rašymas: 0.00232171

10000 įrašų generavimas: 0.0650027
10000 įrašų nuskaitymas: 0.129692
10000 įrašų rikiavimas (sort f-ja) mažėjimo tvarka: 0.0119538
10000 įrašų dalijimas į 'protingus' ir 'kvailus': 0.00969817
'Protingų' studentų įrašų rašymas: 0.0261712
'Kvailų' studentų įrašų rašymas: 0.0184753

100000 įrašų generavimas: 0.677991
100000 įrašų nuskaitymas: 1.28729
100000 įrašų rikiavimas (sort f-ja) mažėjimo tvarka: 0.114524
100000 įrašų dalijimas į 'protingus' ir 'kvailus': 0.090306
'Protingų' studentų įrašų rašymas: 0.251672
'Kvailų' studentų įrašų rašymas: 0.177386

1000000 įrašų generavimas: 6.79087
1000000 įrašų nuskaitymas: 13.0077
1000000 įrašų rikiavimas (sort f-ja) mažėjimo tvarka: 1.12655
1000000 įrašų dalijimas į 'protingus' ir 'kvailus': 0.95812
'Protingų' studentų įrašų rašymas: 2.59083
'Kvailų' studentų įrašų rašymas: 1.82168

10000000 įrašų generavimas: 68.7463
10000000 įrašų nuskaitymas: 135.182
10000000 įrašų rikiavimas (sort f-ja) mažėjimo tvarka: 12.339
10000000 įrašų dalijimas į 'protingus' ir 'kvailus': 13.9433
'Protingų' studentų įrašų rašymas: 28.8242
'Kvailų' studentų įrašų rašymas: 21.2414