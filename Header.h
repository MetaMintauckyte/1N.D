//#ifndef INC_1_0V_HEADER_H
//#define INC_1_0V_HEADER_H
#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <vector>
#include <map>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cctype>
#include <chrono>
#include <list>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
using std::string;
using std::cout;
using std::setw;
using std::ifstream;
using std::list;
using std::left;
using std::fixed;
using std::setprecision;
using std::endl;
using std::clock_t;
//using std::remove_if;
//using std::sort;


using std::vector;
using std::map;
using std::mt19937;


struct irasas {
    string Vard, Pav;
    int egz = 1;
    vector<int> pazymiai;
    float GP = 0; 
    float GP_med = 0;

};

class Timer
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
    Timer() : start{ std::chrono::high_resolution_clock::now() } {}
    void reset() {
        start = std::chrono::high_resolution_clock::now();
    }
    double elapsed() const {
        return std::chrono::duration<double>
                (std::chrono::high_resolution_clock::now() - start).count();
    }
};


irasas calculations(irasas mas) {
    mas.GP = mas.GP / 5.0f;
    mas.GP = mas.GP * 0.4f + 0.6f * mas.egz;

    clock_t begin = clock();
    std::sort(mas.pazymiai.begin(), mas.pazymiai.end());
    if (mas.pazymiai.size() % 2 == 1) {
        mas.GP_med = float(mas.pazymiai[mas.pazymiai.size() / 2]);
        mas.GP_med = mas.GP_med * 0.4f + 0.6f * mas.egz;
    }
    else {
        mas.GP_med = (mas.pazymiai[mas.pazymiai.size() / 2] + mas.pazymiai[(mas.pazymiai.size() / 2) - 1]) / 2.0f;
        mas.GP_med = mas.GP_med * 0.4f + 0.6f * mas.egz;
    }
    return mas;
}

list<irasas> reading_file(string file_name, int stud_k) {
    ifstream MyReadFile(file_name);
    if (!MyReadFile) {
        cout << "\nNepavyko pasiekti failo, pasitkrinkite ar jis tikrai tokiu pavadinimu.\n";
        exit(1);
    }
    cout << "Pavyko atidaryti faila... \n";
    irasas mas;
    list<irasas> mas_list;

    //nuskaitome
    while (!MyReadFile.eof()) {

        MyReadFile >> mas.Vard >> mas.Pav;
        int pazymys = 1;
        for (int i = 0; i < 5; i++) {
            MyReadFile >> pazymys;
            mas.GP = mas.GP + (float)pazymys;
            mas.pazymiai.push_back(pazymys);
        }
        MyReadFile >> mas.egz;
        //skaiciuojame
        mas = calculations(mas);
        //Pridejimas i sarasa
        mas_list.push_back(mas);
        //saraso isvalymas isvalymas
        mas.pazymiai.clear();

    }
    // uzdarome
    MyReadFile.close();
    return mas_list;
}

void create_file_from_list(list<irasas> mas_list, string file_name) {

    ofstream File;
    File.open(file_name);

    File << "Vardas         Pavarde          Galutinis (Vid.)   Galutinis (Med.)";
    File << "\n-------------------------------------------------------------\n";
    for (irasas mas : mas_list) {
        File << left << setw(16) << mas.Vard;
        File << left << setw(16) << mas.Pav;

        File << left << setw(20) << fixed << setprecision(2) << mas.GP;
        File << left << setw(16) << fixed << setprecision(2) << mas.GP_med << endl;
    }
    //Duomenu isvalymas ir uzdarymas
    mas_list.clear();
    File.close();
}

void testavimas(int stud_k, string base_file, string nusk_file, string prot_file) {
    Timer t;
    //cout << "Skaitome faila... \n";
    Timer t2;
    list<irasas> mas_list = reading_file(base_file, stud_k);
    cout << "Failo nuskaitymas uztruko: " << t2.elapsed() << " s\n";

    //cout << "Rusiuojame... \n";
    Timer t3;
    list<irasas> mas_list_nuskriausti;

    for (irasas mas : mas_list) {
        if (mas.GP < 5.0f) {
            mas_list_nuskriausti.push_back(mas);
        }
    }
    mas_list.erase(std::remove_if(mas_list.begin(), mas_list.end(), [](irasas mas)
    {
        return mas.GP < 5.0f;
    }), mas_list.end());

    cout << "Failo rusiavimas uztruko: " << t3.elapsed() << " s\n";


    cout << "Sukuriame failus...\n";
    Timer t4;
    create_file_from_list(mas_list, prot_file);
    //cout << "Failo 'protingi' kurimas uztruko: " << t4.elapsed() << " s\n";
    Timer t5;
    create_file_from_list(mas_list_nuskriausti, nusk_file);
    //cout << "Failo 'nuskriausti' kurimas uztruko: " << t4.elapsed() << " s\n";

    cout << "\n";
    cout << "Bendrai uztruko: " << t.elapsed() << " s\n" << "\n";
}
#ifndef INC_1_0V_HEADER_H
#define INC_1_0V_HEADER_H

#endif //INC_1_0V_HEADER_H
