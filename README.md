**V1.0**

Naudojimosi instrukcija:

Norint, jog programa pilnai veiktų būtina sukurti failus su pavadinimais: studentai_1k.txt, studentai_10k.txt, studentai_100k.txt, studentai_1kk.txt. Šiose failuose programa FileGenerator.cpp atsitiktinai sugeneruoja studento vardą, pavardę, namų darbų pažymius, egzamino įvertinimą.

Struktūroje "įrašas" yra saugoma informacija apie studentą.

Atliekamos dvi strategijos (vector ir list tipo). Gauti testavimo rezultatai pavaizduoti lentelėje:

--------------------**Vector duomenų tipas:** ---------------------------------------------------**List duomenų tipas**---------------------------------

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

