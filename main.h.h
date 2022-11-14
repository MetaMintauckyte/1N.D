#include<iostream>
#include<string>
#include<iomanip>
#include<bits/stdc++.h>
#include <fstream>
#include <ctime>
#include <vector>
#include <sstream>
#include <string>

using namespace std;
using std::string;
using std::vector;
using std::endl;

struct irasas { //Sukuriama struktūra
    string Vard;
    string Pav;
    vector<int> paz;
    int egz;
    float Galut=0; //Galutinis rezultatas float tipo gali būti po kablelio
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
        File << setw(16) << left << mas[i].Vard << setw(16) << left << mas[i].Pav << setw(19) << left << mas[i].Galut << setw(10) << left << mas[i].Med<< endl;
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

void ProtingiNuskriaustiList(list<irasas>mas){
    list<irasas>nuskriausti;
    list<irasas>protingi;
    int listSize=mas.size();

    clock_t begin = clock();
    mas.sort(LygInter);

    list<irasas>::iterator it=mas.begin();
    while(it!=mas.end()){
        if ((*it).Galut < 5) {
            nuskriausti.push_back(*it);
        } else {
            protingi.push_back(*it);
        }
            ++it;
    }
    clock_t end = clock();
    cout << listSize << " Irasu dalijimo i dvi grupes laikas (List): ";
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

vector<irasas>SkaitytiNuoFailo (string fileName){
    clock_t begin = clock();
    ifstream inputFile(fileName);
    string line;
    vector<irasas>vektorius;//create a vector of Student objects
    if(inputFile)
    {
        int k;
        k = 0;
        while(getline(inputFile, line))
        {
            k++;
            if (k < 2)
            continue;
            irasas StudentoObjektas;
            istringstream st(line);
            st >> StudentoObjektas.Vard; //read the firstName
            st >> StudentoObjektas.Pav; //read the lastName
            for (int i = 0; i< 5; i++){
                string nd;
                st >> nd;
                //cout << nd << endl;
                StudentoObjektas.paz.push_back(stoi(nd));
            }
            st >> StudentoObjektas.Galut;

            if(st)//check if input succeded
            {
                vektorius.push_back(StudentoObjektas);//add the studentObject into the vector
            }
        }
    }
    else
    {
        cout << "Failas negali buti atidarytas" << endl;
    }
    clock_t end = clock();
    cout << endl << "Failo is " << vektorius.size() << " irasu nuskaitymo laikas (Vector): ";
    SkaiciavimasAtspausdinimas(begin, end);

    return vektorius;
}

list<irasas>SkaitytiNuoFailoSaraso (string fileName){
    clock_t begin = clock();
    ifstream inputFile(fileName);
    string line;
    list<irasas>Sarasas;//create a list of Student objects
    if(inputFile)
    {
        int k;
        k = 0;
        while(getline(inputFile, line))
        {
            k++;
            if (k < 2)
            continue;
            irasas StudentoObjektas;
            istringstream st(line);
            st>>StudentoObjektas.Vard; //read the firstname
            st>>StudentoObjektas.Pav; //read the lastname
            for (int i = 0; i< 5; i++){
                string nd;
                st >> nd;
                //cout << nd << endl;
                StudentoObjektas.paz.push_back(stoi(nd));
            }
            st >>StudentoObjektas.Galut;

            if(st)//check if input succeded
            {
                Sarasas.push_back(StudentoObjektas);//add the studentObject into the list
            }
        }
    }
    else
    {
        cout << "Failas negali buti atidarytas" << endl;
    }

    clock_t end = clock();
    cout<<"Failo is "<<Sarasas.size() << " irasu nuskaitymo laikas (List): ";
    SkaiciavimasAtspausdinimas(begin, end);

    return Sarasas;
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
    ProtingiNuskriausti(mas);
    clock_t end = clock();

    cout << endl << mas.size() << " Irasu testavimo laikas: ";
    SkaiciavimasAtspausdinimas(begin, end);

    cout << endl;

    return mas;
}
