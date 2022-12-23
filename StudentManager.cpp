#include "StudentManager.h"
vector<Studentas> StudentManager::readStudentus(string file_name, int studentu_sk) {
    ifstream MyReadFile(file_name);
    if (!MyReadFile) {
        cout << "\nNepavyko pasiekti failo, pasitkrinkite ar jis tikrai tokiu pavadinimu.\n";
        exit(1);
    }


    while (!MyReadFile.eof()) {
        string vardas;
        string pavarde;
        MyReadFile >> vardas >> pavarde;
        float pazymys = 1;
        vector<float> pazymiai;
        for (int i = 0; i < 5; i++) {
            MyReadFile >> pazymys;
            pazymiai.push_back(pazymys);
        }
        float egz;
        MyReadFile >> egz;
        Studentas studentas(vardas, pavarde, egz, pazymiai);
        studentas.setGP(studentas.skaiciuok());
        studentai_.push_back(studentas);
    }
    return studentai_;
}

void StudentManager::createStudents(string file_name, bool Failed) {

    ofstream File;
    File.open(file_name);

    File << "Vardas          Pavarde         Galutinis (Vid.)";
    File << "\n----------------------------------------------------\n";
    vector<Studentas> studentai = Failed ? failed_ : studentai_;
    for (Studentas stud : studentai) {
        File << left << setw(16) << stud.getVardas();
        File << left << setw(16) << stud.getPavarde();

        File << left << setw(20) << fixed << setprecision(2) << stud.getGP() << endl;
    }
    // uzdarymas
    File.close();
}

void StudentManager::testing(int studentu_sk, string base_file, string nusk_file, string prot_file) {
    Timer t;
    studentai_ = this->readStudentus(base_file, studentu_sk);
    cout << "Failo nuskaitymas uztruko: " << t.elapsed() << " s\n";


    Timer t2;
    /*
    for (int i = 0; i < studentai_.size(); i++) {
        if (students_[i].getGP() < 5) {
            failed_.push_back(studentai_[i]);
            studentai_.erase(studentai_.begin() + i);
            i--;
        }
    }
    */
    
    vector<Studentas>::iterator it = studentai_.begin();
    while (it != studentai_.end()) {
        if ((*it).getGP() < 5.0f) {
            failed_.push_back(*it);
            it = studentai_.erase(it);
        }
        else ++it;
    }
    cout << "Failo rusiavimas uztruko: " << t2.elapsed() << " s\n";

    cout << "Kuriame failus...\n";
    this->createStudents(prot_file, false);
    this->createStudents(nusk_file, true);

    cout << "Bendrai uztruko: " << t.elapsed() << " s\n" << "\n";
}