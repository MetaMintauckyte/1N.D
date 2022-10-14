#include<iostream>
#include<string>
#include<iomanip>
#include<bits/stdc++.h>
#include <fstream>
#include <ctime>
#include <vector>
#include <sstream>
//#include "Head.h"

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

bool LygInter(irasas i1, irasas i2)
{
    return (i1.Galut < i2.Galut);
}

string ToString(int value){
    stringstream ss;
    std::string s;
    ss << value;
    ss >> s;

    return s;
}

void SkaiciavimasAtspausdinimas(clock_t begin, clock_t end){
    double timer = double(end - begin) / CLOCKS_PER_SEC;
    cout << timer << endl;
}

float Galutinis(int egz, vector<int>paz)
{
    int sum=0;
    int cpaz = paz.size();
    for(int i=0; i < cpaz; i++)
    {
        sum=sum+paz[i];
    }
    float vid = sum/(float)cpaz;
    return (0.6*egz)+(vid*0.4);
}

int Mediana(vector<int>r){
    int size = r.size();
    sort(r.begin(), r.end());
    if (size % 2 != 0)
        return r[size/2];
    return (r[(size-1)/2]+r[size/2])/2.0;
}

void SpausdintiStudentus(vector<irasas>mas, string fileName)
{
    fileName = "files/" + fileName + "-studentai.txt";
    ofstream File;
    File.open(fileName.c_str());

    for(int i=0; i < mas.size(); i++)
    {
        File << setw(10) << left << mas[i].Vard << setw(10) << left << mas[i].Pav << setw(19) << left << mas[i].Galut << setw(10) << left << mas[i].Med<< endl;
    }
    File.close();
}


bool ProtingiNuskriausti(vector<irasas> mas)
{
    vector<irasas> nuskriausti;
    vector<irasas> protingi;

    clock_t begin = clock();
    sort(mas.begin(), mas.end(), LygInter);
    clock_t end = clock();
    cout << mas.size() << " Irasu rusiavimo didejimo tvarka laikas: ";
    SkaiciavimasAtspausdinimas(begin, end);

    begin = clock();
    for(int i=0; i < mas.size(); i++)
    {
        if(mas[i].Galut < 5)
        {
            nuskriausti.push_back(mas[i]);
        }
        else
        {
            protingi.push_back(mas[i]);
        }
    }
    end = clock();

    cout << mas.size() << " Irasu dalijimas i dvi grupes: ";
    SkaiciavimasAtspausdinimas(begin, end);

    begin = clock();
    SpausdintiStudentus(nuskriausti, ToString(mas.size()) + "nuskriausti");
    end = clock();
    cout << mas.size() << " Irasu nuskriausti studentai irasymas: ";
    SkaiciavimasAtspausdinimas(begin, end);

    begin = clock();
    SpausdintiStudentus(protingi, ToString(mas.size()) + "protingi");
    end = clock();
    cout << mas.size() << " Irasu protingi studentai irasymas: ";
    SkaiciavimasAtspausdinimas(begin, end);
}


irasas SukurkStudent(int cpaz, int studentoId) {
    stringstream ss;
    irasas newStudentas;
    string id;
    ss << studentoId;
    ss >> id;
    newStudentas.Vard = "Vardas" + id;
    newStudentas.Pav = "Pavarde" + id;
    newStudentas.egz = (rand() % 10) + 1;
    for(int i=0;i<cpaz;i++)
    {
        int g = (rand() % 10) + 1;
        newStudentas.paz.push_back(g);
    }

    newStudentas.Galut = Galutinis(newStudentas.egz, newStudentas.paz);
    newStudentas.Med = Mediana(newStudentas.paz);

    return newStudentas;
}

vector<irasas> GaukStudentus(int cStud){
    clock_t begin = clock();
    int cpaz= 5;

    string check;
    vector<irasas>mas;
    for(int i=0; i < cStud; i++)
    {
        irasas vienasStudentas = SukurkStudent(cpaz, i+1);
        mas.push_back(vienasStudentas);
    }

    stringstream ss;
    std::string stringStudentas;
    ss << cStud;
    ss >> stringStudentas;

    SpausdintiStudentus(mas, stringStudentas);

    //vector<irasas> readFromFile = ReadFormFile("1000-students");

    ProtingiNuskriausti(mas);
    clock_t end = clock();

    cout << endl << mas.size() << " Irasu testavimo laikas: ";
    SkaiciavimasAtspausdinimas(begin, end);

    cout << endl;

    return mas;
}

void skaityti(string kursioku_failas, vector<irasas> &mas, int &n)
{
    ifstream K (kursioku_failas);
    irasas studentas;
    string eilute;

    getline(K, eilute); //Nuskaitoma pirma eilutė (be studentų duomenų)
    cout << "Sąrašo antraštė: " << eilute << endl << endl;
    n = 0;
    studentas.paz.resize(5);

    while (true)
    {
        K >> studentas.Vard >> studentas.Pav >> studentas.paz[0] >> studentas.paz[1] >> studentas.paz[2] >> studentas.paz[3] >> studentas.paz[4] >> studentas.egz;

        if (K.eof()) { break; }

        n++;
        mas.push_back(studentas);
    }

    K.close();
}

void vidurkis(vector<irasas> &mas, int stud_nr)
{
    int visi_paz=mas[stud_nr].paz.size();

    for (int x=0; x<visi_paz; x++)
    {    mas[stud_nr].Galut += mas[stud_nr].paz[x]; }

    mas[stud_nr].Galut=mas[stud_nr].Galut/visi_paz;
    mas[stud_nr].Galut=mas[stud_nr].Galut*0.4+0.6*mas[stud_nr].egz;
}

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
    }
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

    while (true)
    {
        cin>>balas;

        if (balas==0) break;

        mas[i].paz.push_back(balas);
    }
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

    cout << endl;
}

void atspausdinti(vector<irasas> &mas, int stud_k)
{
    cout << "Nuskaityti studentų duomenys:"
         << endl<<endl
         << setw(10)<<left<<"Vardas"
         << setw(15)<<left<<"Pavarde";

    for (int j=0; j<mas[0].paz.size(); j++)
    {   cout << setw(4) << "ND" + to_string(j+1); }

    cout << setw(4) <<left<<"Egzaminas"
         << endl;

    for (int i = 0; i < stud_k; i++)
    {
        cout << setw(10)<<mas[i].Vard
             << setw(15)<<mas[i].Pav;

        for (int j=0; j<mas[i].paz.size(); j++)
        {   cout << setw(4) <<mas[i].paz[j]; }

        cout << setw(4) <<mas[i].egz
             << endl;
    }
    cout << endl<<endl;

    cout<<setprecision(3);
    cout << "Apskaičiuoti rezultatai:";
    cout<<endl<<endl; 
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
    cout<<endl;
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
    }
    else
    {
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
        }
    }

    for (int i=0; i<stud_k; i++)
    {
        vidurkis(mas, i);
        mediana(mas, i);
    }

    atspausdinti(mas, stud_k);


  srand(time(0));

    GaukStudentus(1000);
    GaukStudentus(10000);
    GaukStudentus(100000);
    //GaukStudentus(1000000);

    return 0;
}
