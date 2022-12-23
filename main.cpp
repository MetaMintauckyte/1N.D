//#include "Header.h"
#include "FileGenerator.h"
#include "StudentManager.h"

int main() {
    
    Studentas pranas("Pranas", "Peckorius", 8.0, vector<float> {5, 8, 10, 6, 9});
    cout << pranas.getND()[2];
    pranas.setGP(9);
    Studentas pranas2 = pranas;
    cout << pranas2.getND()[2];
    pranas = pranas2;
    cout << pranas.getGP();
    
    

    cout << "Generuojame 1000 irasu\n";
    generator_of_students(1000, "studentai_1k.txt");

    cout << "Generuojame 10000 irasu\n";
    generator_of_students(10000, "studentai_10k.txt");

    cout << "Generuojame 100000 irasu\n";
    generator_of_students(100000, "studentai_100k.txt");

    /*cout << "Generuojame 1000000 irasu\n";
    generator_of_students(1000000, "studentai_1kk.txt");

    cout << "Generuojame 10000000 irasu\n";
    generator_of_students(10000000, "studentai_10kk.txt");*/
    
    StudentManager manager1;
    StudentManager manager2;
    
    cout << "Testuojame su 1000 irasu:\n";
    manager1.testing(1000, "studentai_1k.txt", "nuskriausti_1k.txt", "protingi_1k.txt");
    
    cout << "Testuojame su 10000 irasu:\n";
    manager2.testing(10000, "studentai_10k.txt", "nuskriausti_10k.txt", "protingi_10k.txt");
    
    //cout << "Testuojame su 100000 irasu:\n";
    //manager2.testing(100000, "studentai_100k.txt", "nuskriausti_100k.txt", "protingi_100k.txt");

    //cout << "Testuojame su 1000000 irasu:\n";
    //manager2.testing(1000000, "studentai_1kk.txt", "nuskriausti_1kk.txt", "protingi_1kk.txt");

    return 0;
}