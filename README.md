**V1.0**

Naudojimosi instrukcija:

Norint, jog programa pilnai veiktų būtina sukurti failus su pavadinimais: studentai_1k.txt, studentai_10k.txt, studentai_100k.txt, studentai_1kk.txt. Šiose failuose programa FileGenerator.cpp atsitiktinai sugeneruoja studento vardą, pavardę, namų darbų pažymius, egzamino įvertinimą.

Optimizuojama studentų rūšiavimo į dvi kategorijas (protingi,nuskriausti) realizacija.
 * **1 strategija**: Bendro "studentai" konteinerio skaidymas į du naujus to paties tipo konteinerius: "protingi" ir "nuskriausti". Studentas yra dvejuose konteineriuose: bendrame "studentai" ir viename iš suskaidytų (protingi, nuskriausti).
  * **2 strategija**: Bendro "students" konteinerio skaidymas panaudojant tik vieną naują konteinerį: "nuskriausti". Studentas yra nuskriaustas, jį programa įkelia į naująjį nuskriausti konteinerį ir ištrinti iš bendro "studentai" konteinerio. Po šio žingsnio "studentai" konteineryje liks vien tik protingi.


Struktūroje "įrašas" yra saugoma informacija apie studentą.

Atliekamos dvi strategijos (vector ir list tipo). Gauti testavimo rezultatai pavaizduoti lentelėje:

------------**Vector duomenų tipas:** -----------------Antra strategija------------------**List duomenų tipas**-----------------

|Įrašų apie studentus kiekis|Operacijos|Testavimo laikas|   |Įrašų apie studentus kiekis|Operacijos|Testavimo laikas|
|-----|-----|-----|---|-----|-----|-----|
|1000|nuskaitymas|0.14s |   |1000|nuskaitymas|0.01s |
|1000|rušiavimas|0.0001s |   |1000|rušiavimas|0.0002s |
|10000|nuskaitymas|0.20s |   |10000|nuskaitymas|0.03s |
|10000|rušiavimas|0.001s |   |10000|rušiavimas|0.001s |
|100000|nuskaitymas|0.12s |   |100000|nuskaitymas|2.58s |
|100000|rušiavimas|0.05s |   |100000|rušiavimas|0.31s |
|1000000|nuskaitymas|2.40s |   |1000000|nuskaitymas|3.21s | 
|1000000|rušiavimas|0.44s |   |1000000|rušiavimas|0.40s |
|10000000|nuskaitymas|6.99s |   |10000000|nuskaitymas|4.21s |
|10000000|rušiavimas|0.99s |   |10000000|rušiavimas|0.56s |

------------**Vector duomenų tipas:** -----------------Pirma strategija------------------**List duomenų tipas**-----------------

|Įrašų apie studentus kiekis|Operacijos|Testavimo laikas|   |Įrašų apie studentus kiekis|Operacijos|Testavimo laikas|
|-----|-----|-----|---|-----|-----|-----|
|1000|nuskaitymas|0.09s |   |1000|nuskaitymas|0.04s |
|1000|rušiavimas|0.02s |   |1000|rušiavimas|0.01s |
|10000|nuskaitymas|0.63s |   |10000|nuskaitymas|0.45s |
|10000|rušiavimas|0.14s |   |10000|rušiavimas|0.11s |
|100000|nuskaitymas|4.10s |   |100000|nuskaitymas|4.59s |
|100000|rušiavimas|1.49s |   |100000|rušiavimas|1.27s |
|1000000|nuskaitymas|52.11s |   |1000000|nuskaitymas|48.07s | 
|1000000|rušiavimas|15.13s |   |1000000|rušiavimas|8.40s |
|10000000|nuskaitymas|7.84min |   |10000000|nuskaitymas|6.22min |
|10000000|rušiavimas|4.43min |   |10000000|rušiavimas|4.88min |

