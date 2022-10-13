#include<iostream>
#include<string>
#include<iomanip>
#include<bits/stdc++.h>

using std::cout; 
using std::cin;
using std::endl;
using namespace std;
using std::string;

struct irasas { 
    string Vard;
    string Pav;
    vector<int> paz;
    int egz;
    float Galut=0; 
    float Med=0;
};

void mediana(vector<irasas> &mas, int stud_nr) 
{
    int sk=0; 

    for (int i=0; i<10; i++) 
    {
        if (mas[stud_nr].paz[i]>0)
        {   sk++; }

        if (mas[stud_nr].paz[i]==0) 
        {
          sk--;
          break; 
        }
    }

    if (sk%2==0) 
    {  mas[stud_nr].Med = float(((mas[stud_nr].paz[sk/2-1])+(mas[stud_nr].paz[(sk/2)]))/2.0);}
    else
    {  mas[stud_nr].Med = mas[stud_nr].paz[(sk/2)];}
}

int generavimas() 
{
    return rand()%10+1;
}

void auto_ived_paz(vector<irasas> &mas, int i, int visi_paz) 
{
    mas[i].egz=generavimas(); 

    int balas;

    for (int x=0; x<visi_paz; x++) 
    {
        balas = generavimas();
        mas[i].paz.push_back(balas);
        mas[i].Galut = mas[i].Galut + balas;
    }

    mas[i].Galut=mas[i].Galut/visi_paz;
    mas[i].Galut=mas[i].Galut*0.4+0.6*mas[i].egz;
}

void ivedimas(vector<irasas> &mas, int i) 
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

void vard_ived(vector<irasas> &mas, int i)
{
    cout<<"Įveskite studento numeris: " <<i+1<< " duomenis:\n";

    do {
        cout<<"Įveskite studento numeris: "<<i+1<<" vardą:\n";
        cin>>mas[i].Vard;
    }
      while (mas[i].Vard.length()<0 || mas[i].Vard.length()>15); 
    do {
        cout<<"Įveskite studento numeris: " <<i+1<< " pavardę:\n";
        cin >> mas[i].Pav;
    }
      while (mas[i].Pav.length()<0 && mas[i].Pav.length()>20); 
}

void atspausdinti(vector<irasas> &mas, int stud_k) 
{
    cout<<std::setprecision(3);
    cout<<"\n\n"; 
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

int main()
{
    vector<irasas> mas;
    int stud_k;
    int stud_max = 30;
    char vedimas;

    srand(time(NULL));

    do 
    {
        cout<<"Įveskite studentų kiekį (nuo 1 iki "<<stud_max<<"):\n";
        cin>>stud_k; 
    }
      while (int(stud_k)<0 || int(stud_k)>stud_max); 

    mas.resize(stud_k);

    do {
        cout<<"Ar norite, kad studentų pažymiai būtų suvesti automatiškai? Jei taip rašykite 'T'. Jei ne rašykite 'N'\n";

        cin>>vedimas; 
        if (vedimas!='T' && vedimas!='N') { cout<<"Įveskite iš naujo\n"; } 
    }
      while (vedimas!='T' && vedimas!='N'); 

    for (int i=0; i<stud_k; i++) 
    {
        vard_ived(mas, i);
        if (vedimas=='N') {ivedimas(mas, i);} 
        else {auto_ived_paz(mas,i,6);} 
        mediana(mas, i);
    }

    atspausdinti(mas, stud_k);
    return 0;
