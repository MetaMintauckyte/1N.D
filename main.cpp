#include<iostream>
#include<string>
#include<iomanip>
#include<bits/stdc++.h>

using std::cout; //Priemonės, kad kiekvieną kart nereiktų rašyt std:
using std::cin;
using std::endl;
using namespace std;
using std::string;

struct irasas { //Sukuriama struktūra
    string Vard;
    string Pav;
    vector<int> paz;
    int egz;
    float Galut=0; //Galutinis rezultatas float tipo gali būti po kablelio
    float Med=0;
};

void skaityti(string kursioku_failas, vector<irasas> &mas, int &n)
{
    ifstream K (kursioku_failas);
    irasas studentas;

    K >> n;
    studentas.paz.resize(5);

    for (int i = 0; i < n; i++)
    {
        K >> studentas.Vard >> studentas.Pav >> studentas.paz[0] >> studentas.paz[1] >> studentas.paz[2] >> studentas.paz[3] >> studentas.paz[4] >> studentas.egz;
        mas.push_back(studentas);
    }
    K.close();
}

void mediana(vector<irasas> &mas, int stud_nr) //Funkcija skirta skaičiuoti medianą
{
    int sk=0; //Skaitiklis. Pažymių kiekis

    for (int i=0; i<10; i++) //Indeksas ne didesnis už 10
    {
        if (mas[stud_nr].paz[i]>0)
        {   sk++; }

        if (mas[stud_nr].paz[i]==0) //Sąlyga jei įvedėme pažymį 0 (baigėme rašyti)
        {
          sk--;
          break; //Nutraukiame ciklą
        }
    }

    if (sk%2==0) //Jei skaitiklis yra lyginis skaičius
    {  mas[stud_nr].Med = float(((mas[stud_nr].paz[sk/2-1])+(mas[stud_nr].paz[(sk/2)]))/2.0);}
    else
    {  mas[stud_nr].Med = mas[stud_nr].paz[(sk/2)];}
}

int generavimas() //Sugeneruoja atsitiktinius pažymius nuo 1 iki 10
{
    return rand()%10+1;
}

void auto_ived_paz(vector<irasas> &mas, int i, int visi_paz) // Suvedimo funkcija. Į turimą masyvą mas[] įdedami automatiškai sugeneruoti pažymiai ir egzamino rezultatas
{
    mas[i].egz=generavimas(); //Masyve esantis egzamino rezultatas yra nukreipianas į funkciją void, kur automatiškai generuojami pažymiai nuo 1 iki 10

    int balas;

    for (int x=0; x<visi_paz; x++) //For ciklas
    {
        balas = generavimas();
        mas[i].paz.push_back(balas);
        mas[i].Galut = mas[i].Galut + balas;
    }

    mas[i].Galut=mas[i].Galut/visi_paz;
    mas[i].Galut=mas[i].Galut*0.4+0.6*mas[i].egz;
}

void ivedimas(vector<irasas> &mas, int i) //Funkcija skirta leisti vartotojui suvesti duomenis pačiam
{
    do {
        cout<<"Įveskite studento egzamino pažymį:\n";
        cin>>mas[i].egz;
    }
      while (mas[i].egz<0 || mas[i].egz>10);

    cout<<"Įveskite visus studento pažymius (baigę rašykite '0' ):\n";

    int balas;

    do {
        cin>>balas;
        if (balas!=0)
        {
            mas[i].paz.push_back(balas);
            mas[i].Galut = mas[i].Galut + balas;
        }
    }
      while (balas!=0);

    mas[i].Galut=mas[i].Galut/mas[i].paz.size();
    mas[i].Galut=mas[i].Galut*0.4+0.6*mas[i].egz;
}

void vard_ived(vector<irasas> &mas, int i) //Vardo ir pavardės įvedimo void funkcija
{
    cout<<"Įveskite studento numeris: " <<i+1<< " duomenis:\n";

    do {
        cout<<"Įveskite studento numeris: "<<i+1<<" vardą:\n";
        cin>>mas[i].Vard;
    }
      while (mas[i].Vard.length()<0 || mas[i].Vard.length()>15); //Studento vardas negali būti ilgesnis nei 15 raidžių arba turėsime pakartoti įvedimą

    do {
        cout<<"Įveskite studento numeris: " <<i+1<< " pavardę:\n";
        cin >> mas[i].Pav;
    }
      while (mas[i].Pav.length()<0 && mas[i].Pav.length()>20); //Studento pavardė negali būti ilgesnė nei 20 raidžių arba turėsime pakartoti įvedimą

    cout << endl;
}

void atspausdinti(vector<irasas> &mas, int stud_k) //Resultato atspausdinimas
{
    cout << "Nuskaityti studentų duomenys:"
         << endl<<endl
         << setw(10)<<left<<"Vardas"
         << setw(15)<<left<<"Pavarde"
         << setw(4) <<left<<"ND1"
         << setw(4) <<left<<"ND2"
         << setw(4) <<left<<"ND3"
         << setw(4) <<left<<"ND4"
         << setw(4) <<left<<"ND5"
         << setw(4) <<left<<"Egzaminas"
         << endl;

    for (int i = 0; i < stud_k; i++)
    {
        cout << setw(10)<<mas[i].Vard
             << setw(15)<<mas[i].Pav
             << setw(4) <<mas[i].paz[0]
             << setw(4) <<mas[i].paz[1]
             << setw(4) <<mas[i].paz[2]
             << setw(4) <<mas[i].paz[3]
             << setw(4) <<mas[i].paz[4]
             << setw(4) <<mas[i].egz
             << endl;
    }
    cout << endl<<endl;

    cout << "Apskaičiuoti rezultatai:";
    cout<<std::setprecision(3);
    cout<<endl<<endl; //Tuščia eilutė
    cout<<setw(21)<<left<<"Vardas";
    cout<<setw(21)<<left<<"Pavardė";
    cout<<setw(18)<<left<<"Galutinis(vid.)";
    cout<<left<<"Galutinis(med.)\n";
    cout<<"------------------------------------------------------------------------------\n";

    for (int i=0; i<stud_k; i++)
    {
        cout<<setw(21)<<left<<mas[i].Vard;
        cout<<setw(21)<<left<<mas[i].Pav;
        cout<<setw(18)<<left<<mas[i].Galut;
        cout<<setw(18)<<left<<mas[i].Med;
        cout<<endl;
    }
}

int main(int argc, char *argv[])
{
    vector<irasas> mas;
    int stud_k;
    int stud_max = 30;
    char vedimas;

    if (argc>1)
    {
        skaityti(argv[1], mas, stud_k);
        //mediana(mas, i);
    }
    else
    {
        srand(time(NULL));

        do //Kilpa, kuri neleis įvesti netinkamą studentų skaičių
        {
            cout<<"Įveskite studentų kiekį (nuo 1 iki "<<stud_max<<"):\n";
            cin>>stud_k; //Įvedamas studentų kiekis
        }
          while (int(stud_k)<0 || int(stud_k)>stud_max); //Studentų negali būti daugiau nei nurodyta konstantoje stud_max, dabartiniu atveju 30

        mas.resize(stud_k);

        do {
            cout<<"Ar norite, kad studentų pažymiai būtų suvesti automatiškai? Jei taip rašykite 'T'. Jei ne rašykite 'N'\n";

            cin>>vedimas; //Įrašome T arba N
            if (vedimas!='T' && vedimas!='N') { cout<<"Įveskite iš naujo\n"; } //Jei įvestas simbolis nebuvo T arba N, tada vedame iš naujo, kol įvesime teisingai
        }
          while (vedimas!='T' && vedimas!='N'); //Ciklas kai įvedėme teisingai

        for (int i=0; i<stud_k; i++) //For ciklas su indeksu i, kuris yra mežesnis už įvestų studentų kiekį, jog žinotume kiek kartų prašyti vardo įvedimo ir t.t
        {
            vard_ived(mas, i);
            if (vedimas=='N') {ivedimas(mas, i);} //Jei pasirinkome duomenis suvesti pačiam, tai kviečiama void funkcija
            else {auto_ived_paz(mas,i,6);} //Jei pasirinkome kad duomenys būtų suvesti automatiškai
            mediana(mas, i);
        }
    }

    atspausdinti(mas, stud_k); //Rezultatų atspausdinimas (void funkcijos)
    return 0;
}
