#include <iostream>
#include "StudentManager.h"
#include "FileGenerator.h"

int main() {
    StudentManager manager1;
    StudentManager manager2;

    int a;
    cout<<"Jei norite sugeneruoti failus rasykite: 1  .";
    cout<<"Jei norite testuoti irasus rasykite: 2"<<endl;
    cin>>a;
    //a = 0;
    cin>>a;
    if (a==1){
    cout << "Generuojame 1000 irasu\n";
    generator_of_students(1000, "studentai_1k.txt");

    cout << "Generuojame 10000 irasu\n";
    generator_of_students(10000, "studentai_10k.txt");

    /*cout << "Generuojame 100000 irasu\n";
    generator_of_students(100000, "studentai_100k.txt");

    cout << "Generuojame 1000000 irasu\n";
    generator_of_students(1000000, "studentai_1kk.txt");

    cout << "Generuojame 10000000 irasu\n";
    generator_of_students(10000000, "studentai_10kk.txt");*/}
    else  {
    cout << "Testuojame su 1000 irasu:\n";
    manager1.testing(1000, "studentai_1k.txt", "nuskriausti_1k.txt", "protingi_1k.txt");

    cout << "Testuojame su 10000 irasu:\n";
    manager2.testing(10000, "studentai_10k.txt", "nuskriausti_10k.txt", "protingi_10k.txt");}

    //cout << "Testuojame su 100000 irasu:\n";
    //manager2.testing(100000, "studentai_100k.txt", "vargsiukai_100k.txt", "galvociai_100k.txt");

    //cout << "Testuojame su 1000000 irasu:\n";
    //manager2.testing(1000000, "studentai_1kk.txt", "vargsiukai_1kk.txt", "galvociai_1kk.txt");

    return 0;
}
