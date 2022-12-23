#pragma once
#include "Studentas.h"

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

class StudentManager {
private:
    vector<Studentas>studentai_;
    vector<Studentas>failed_;
public:
    StudentManager() {

    }
    vector<Studentas> readStudentus(string file_name, int studentu_sk);
    void createStudents(string file_name, bool Failed);
    void testing(int studentu_sk, string base_file, string nusk_file, string prot_file);

    void setStudents(vector<Studentas>studentai) {
        studentai_ = studentai;
    }
    vector<Studentas> getStudentai() {
        return studentai_;
    }

    void setFailed(vector<Studentas>studentai) {
        failed_ = studentai;
    }
    vector<Studentas> getFailed() {
        return failed_;
    }
};

