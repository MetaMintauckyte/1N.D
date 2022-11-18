#include<iostream>
#include<string>
#include<iomanip>
#include<bits/stdc++.h>
#include <fstream>
#include <ctime>
#include <vector>
#include <sstream>

using std::cout; //Priemonės, kad kiekvieną kart nereiktų rašyt std:
using std::cin;
using std::endl;
using namespace std;
using std::string;

#include"main.h"

int main(int argc, char *argv[])
{
    vector<irasas> mas;
    int stud_k;
    int stud_max = 30;
    char vedimas;
    char *failas;


    srand(time(0));

    cin.exceptions(std::istream::failbit);
    try
    {
        cout << "Iveskite studentu kieki: ";
        cin >> stud_k;
        GaukStudentus(stud_k);
    }


    catch(const ios_base::failure& e)
    {
        cout << "Netinkamai ivestas studentu kiekis" << endl;
        cout << e.what() << endl;
    }

    return 0;
}
