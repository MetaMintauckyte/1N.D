#pragma once
#include "Header.h"
class Zmogus
{
protected: //pasiekia išvestinės klasės
	string vardas_;
	string pavarde_;
public:
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
    }
};

