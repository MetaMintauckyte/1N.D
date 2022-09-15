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
    int paz[10]={0};
    int egz;
    float Galut=0; //Galutinis rezultatas float tipo gali būti po kablelio
};

void mediana(int pazymiai[]) //Funkcija skirta skaičiuoti medianą
{
    int sk=0; //Skaitiklis. Pažymių kiekis
    for (int i=0; i<10; i++) //Indeksas ne didesnis už 10
    {
        if (pazymiai[i]>0)
        {   sk++; }
        if (pazymiai[i]==0) //Sąlyga jei įvedėme pažymį 0 (baigėme rašyti)
        {  pazymiai[i]=0;
          sk--;
          break;} //Nutraukiame ciklą       
    }
    if (sk%2==0) //Jei skaitiklis yra lyginis skaičius
    {  cout<<float(((pazymiai[sk/2-1])+(pazymiai[(sk/2)]))/2.0);}
    else
    {  cout<<pazymiai[(sk/2)];}
    cout<<endl;
}

int generavimas() //Sugeneruoja atsitiktinius pažymius nuo 1 iki 10
{
    srand(time(NULL));
    return rand()%10+1; 
}
void auto_ived_paz(irasas mas[], int i, int visi_paz) // Suvedimo funkcija. Į turimą masyvą mas[] įdedami automatiškai sugeneruoti pažymiai ir egzamino rezultatas
{
    mas[i].egz=generavimas(); //Masyve esantis egzamino rezultatas yra nukreipianas į funkciją void, kur automatiškai generuojami pažymiai nuo 1 iki 10
    for (int x=0; x<visi_paz; x++) //For ciklas
    {
        mas[i].paz[x]=generavimas();
    }
    mas[i].Galut=mas[i].Galut/visi_paz;
    mas[i].Galut=mas[i].Galut*0.4+0.6*mas[i].egz;
}
void ivedimas(irasas mas[], int i) //Funkcija skirta leisti vartotojui suvesti duomenis pačiam
{
    do {
        cout<<"Įveskite studento egzamino pažymį:\n";
        cin>>mas[i].egz;
    } 
      while (mas[i].egz<0 || mas[i].egz>10);
    cout<<"Įveskite visus studento pažymius (baigę rašykite '0' ):\n";
    int sk=0; //Skaitiklis. Skaičių kiekis
    do {
        cin>>mas[i].paz[sk];
        if (mas[i].paz[sk]!=0)  { mas[i].Galut = mas[i].Galut+(float)mas[i].paz[sk]; }
        sk++;
    } 
      while (mas[i].paz[sk-1]!=0);
    sk--;
    mas[i].Galut=mas[i].Galut/sk;
    mas[i].Galut=mas[i].Galut*0.4+0.6*mas[i].egz;
}

void vard_ived(irasas mas[], int i) //Vardo ir pavardės įvedimo void funkcija
{
    cout<<"Įveskite studento numeris: " <<i+1<< " duomenis:\n";
    do {
        cout<<"Įveskite studento numeris: "<<i+1<<" vardą:\n";
        cin>>mas[i].Vard;
    } while (mas[i].Vard.length()<0 || mas[i].Vard.length()>15); //Studento vardas negali būti ilgesnis nei 15 raidžių arba turėsime pakartoti įvedimą
    do {
        cout<<"Įveskite studento numeris: " <<i+1<< " pavardę:\n";
        cin >> mas[i].Pav;
    } while (mas[i].Pav.length()<0 && mas[i].Pav.length()>20); //Studento pavardė negali būti ilgesnė nei 20 raidžių arba turėsime pakartoti įvedimą  
}

void atspausdinti(irasas mas[], int stud_k) //Resultato atspausdinimas
{
    cout<<"\n\n"; //Tuščia eilutė
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
        mediana(mas[i].paz);
    }
}
int main()
{
    char vedimas;
    int stud_k; //Studentų kiekis
  
    do //Kilpa, kuri neleis įvesti netinkamą studentų skaičių
    {
        cout<<"Įveskite studentų kiekį (nuo 1 iki 30):\n";
        cin>>stud_k; //Įvedamas studentų kiekis
    } while (int(stud_k)<0 || int(stud_k)>30); //Studentų negali būti daugiau nei 30
    irasas mas[25];

    do
    {
        cout<<"Ar norite, kad studentų pažymiai būtų suvesti automatiškai? Jei taip rašykite 'T'. Jei ne rašykite 'N'\n";
      
        cin>>vedimas; //Įrašome T arba N
        if (vedimas!='T' && vedimas!='N') { cout<<"Įveskite iš naujo\n"; } //Jei įvestas simbolis nebuvo T arba N, tada vedame iš naujo, kol įvesime teisingai
    } while (vedimas!='T' && vedimas!='N'); //Ciklas kai įvedėme teisingai
    for (int i=0; i<stud_k; i++) //For ciklas su indeksu i, kuris yra mežesnis už įvestų studentų kiekį, jog žinotume kiek kartų prašyti vardo įvedimo ir t.t
    {
        vard_ived(mas, i);
        if (vedimas=='N') {ivedimas(mas, i);} //Jei pasirinkome duomenis suvesti pačiam, tai kviečiama void funkcija
        else {auto_ived_paz(mas,i,6);} //Jei pasirinkome kad duomenys būtų suvesti automatiškai
    }
    atspausdinti(mas, stud_k); //Rezultatų atspausdinimas (void funkcijos)
    return 0;
}
