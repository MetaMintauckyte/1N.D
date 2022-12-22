#include "Studentas.h"
float Studentas::skaiciuok() {

    for (float paz : nd_) {
        galutinis_pazymys_ += paz;
    }
    galutinis_pazymys_ /= 5.0f;
    galutinis_pazymys_ = galutinis_pazymys_ * 0.4f + egzaminas_ * 0.6f;
    return galutinis_pazymys_;
}