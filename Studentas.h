#pragma once
#include "Zmogus.h"
class Studentas : public Zmogus
{
private:
    //string vardas_;
    //string pavarde_;
    float Egz;
    std::vector<float> nd_;
    float GalutPaz;
public:
    Studentas(string vard, string pavard, float egzam, vector<float> nd) {
        vardas_ = vard;
        pavarde_ = pavard;
        Egz = egzam;
        nd_ = nd;
    }
    
    ~Studentas() {
 
    }

    Studentas(const Studentas& stud2) {
        vardas_ = stud2.vardas_;
        pavarde_ = stud2.pavarde_;
        Egz = stud2.Egz;
        for (int i = 0; i < stud2.nd_.size(); i++)
            nd_.push_back(stud2.nd_[i]);
        GalutPaz = stud2.GalutPaz;
    }
    
    Studentas& operator=( const Studentas& stud2) {
        vardas_ = stud2.vardas_;
        pavarde_ = stud2.pavarde_;
        Egz = stud2.Egz;
        nd_ = stud2.nd_;
        GalutPaz = stud2.GalutPaz;
        return *this;
    }
    

    float skaiciuok();
    /*
    void setVardas(string v) {
        vardas_ = v;
    }
    string getVardas() {
        return vardas_;
    }

    void setPavarde(string p) {
        pavarde_ = p;
    }
    string getPavarde() {
        return pavarde_;
    }*/

    void setEgzaminas(float e) {
        Egz = e;
    }
    double getEgzaminas() {
        return Egz;
    }

    void setND(vector<float> nd) {
        nd_ = nd;
    }
    vector<float> getND() {
        return nd_;
    }

    void setGP(float gp) {
        GalutPaz = gp;
    }
    float getGP() {
        return GalutPaz;
    }
};

