Atliekamas konteinerių testavimas: išmatuojama patobulintos v0.3 realizacijos veikimo sparta priklausomai nuo naudojamo vieno iš dviejų konteinerių:
std::vector
std::list
Tiek failų kūrimas, tiek ir surūšiuotų rezultatų išvedimas į failus nepriklauso nuo naudojamo konteinerio, todėl v0.4.1 versijoje matuojami šie programoje atliekami žingsniai (patobulinta programos veikimo greičio (spartos) analizė):

 *duomenų nuskaitymas iš failų;
 *studentų rūšiavimas (dalijimas) į dvi grupes/kategorijas;
Testavimas atliekamas su tais pačiais failais, sudarytais iš 1 000, 10 000, 100 000, 1 000 000 įrašų.

Jei failas jau egzistuoja anksčiau direktorijoje sukurtame "files/" aplankale, programos veikimo greičio (spartos) analizė atliekama su anksčiau sugeneruotu failu.
Jei failas dar neegzistuoja, pirmiausia failas sugeneruojamas, vartotojui į konsolę įvedant, kokį failą norima generuoti, ir tik tuomet vykdoma programos spartos analizė.
