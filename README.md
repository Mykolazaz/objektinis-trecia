## Studentų duomenų apdorojimo programa
- Generuoja studentų informaciją: namų darbai (tarpiniai rezultatai) ir egzamino rezultatai
- Leidžia duomenis įvesti rankomis arba nuskaityti iš failo
- Informacija išvedama į failą sulygiuota ir išrikiuota pagal pavardę
- Studentus suskirsto į "protingus" ir "kvailus" ir juos išveda į failą atskirai

Panaudotos bibliotekos: iostream, vector, sstream, random, algorithm, fstream, iomanip, stdexception, chrono, list.

### Programos veikimo greičio (spartos) analizė (vidurkiai)
Testavimo įranga:
- CPU: Apple M1
- RAM: 8 GB LPDDR4X-4266
- SSD: 256 GB ~2700 MB/s


#### Pastaba. (1) - std::vector, (2) - std::list.

### Testavimas
##### 1000 įrašų failas
- Generavimas: 0.00696813

- Įrašų nuskaitymas: 0.00926296
- Įrašų rikiavimas (sort f-ja) mažėjimo tvarka: 0.00019525
- Įrašų dalijimas į 'protingus' ir 'kvailus': 0.000511292
- 'Protingų' studentų įrašų rašymas: 0.00485875
- 'Kvailų' studentų įrašų rašymas: 0.00408129

- Bendras veikimo laikas be generavimo: 0.0189665

- Įrašų nuskaitymas: 0.00601721
- Įrašų rikiavimas (sort f-ja) mažėjimo tvarka: 0.000147083
- Įrašų dalijimas į 'protingus' ir 'kvailus': 0.000465584
- 'Protingų' studentų įrašų rašymas: 0.00323946
- 'Kvailų' studentų įrašų rašymas: 0.00330871

- Bendras veikimo laikas be generavimo: 0.013227

##### 10000 įrašų failas
- Generavimas: 0.0473278

- Įrašų nuskaitymas: 0.0525183
- Įrašų rikiavimas (sort f-ja) mažėjimo tvarka: 0.00102446
- Įrašų dalijimas į 'protingus' ir 'kvailus': 0.00267792
- 'Protingų' studentų įrašų rašymas: 0.0186727
- 'Kvailų' studentų įrašų rašymas: 0.0154272

- Bendras veikimo laikas be generavimo: 0.090366

- Įrašų nuskaitymas: 0.0233253
- Įrašų rikiavimas (sort f-ja) mažėjimo tvarka: 0.00110883
- Įrašų dalijimas į 'protingus' ir 'kvailus': 0.00189529
- 'Protingų' studentų įrašų rašymas: 0.0134973
- 'Kvailų' studentų įrašų rašymas: 0.0130723

- Bendras veikimo laikas be generavimo: 0.0529387

##### 100000 įrašų failas
- Generavimas: 0.247691

- Įrašų nuskaitymas: 0.260198
- Įrašų rikiavimas (sort f-ja) mažėjimo tvarka: 0.00634958
- Įrašų dalijimas į 'protingus' ir 'kvailus': 0.024852
- 'Protingų' studentų įrašų rašymas: 0.128943
- 'Kvailų' studentų įrašų rašymas: 0.127124

- Bendras veikimo laikas be generavimo: 0.547536

- Įrašų nuskaitymas: 0.219515
- Įrašų rikiavimas (sort f-ja) mažėjimo tvarka: 0.0308167
- Įrašų dalijimas į 'protingus' ir 'kvailus': 0.0384334
- 'Protingų' studentų įrašų rašymas: 0.137946
- 'Kvailų' studentų įrašų rašymas: 0.132534

- Bendras veikimo laikas be generavimo: 0.559315

##### 1000000 įrašų failas
- Generavimas: 1.99527

- Įrašų nuskaitymas: 2.22236
- Įrašų rikiavimas (sort f-ja) mažėjimo tvarka: 0.0655359
- Įrašų dalijimas į 'protingus' ir 'kvailus': 0.365903
- 'Protingų' studentų įrašų rašymas: 1.37404
- 'Kvailų' studentų įrašų rašymas: 1.3329

- Bendras veikimo laikas be generavimo: 5.36082

- Įrašų nuskaitymas: 2.1868
- Įrašų rikiavimas (sort f-ja) mažėjimo tvarka: 0.683623
- Įrašų dalijimas į 'protingus' ir 'kvailus': 0.544798
- 'Protingų' studentų įrašų rašymas: 1.34336
- 'Kvailų' studentų įrašų rašymas: 1.30647

- Bendras veikimo laikas be generavimo: 6.06513

##### 10000000 įrašų failas
- Generavimas: 18.9827

- Įrašų nuskaitymas: 23.3002
- Įrašų rikiavimas (sort f-ja) mažėjimo tvarka: 0.905732
- Įrašų dalijimas į 'protingus' ir 'kvailus': 10.3277
- 'Protingų' studentų įrašų rašymas: 13.9868
- 'Kvailų' studentų įrašų rašymas: 15.6075

- Bendras veikimo laikas be generavimo: 64.128

- Įrašų nuskaitymas: 22.7823
- Įrašų rikiavimas (sort f-ja) mažėjimo tvarka: 12.1017
- Įrašų dalijimas į 'protingus' ir 'kvailus': 74.2692
- 'Protingų' studentų įrašų rašymas: 14.523
- 'Kvailų' studentų įrašų rašymas: 14.5429

- Bendras veikimo laikas be generavimo: 138.219