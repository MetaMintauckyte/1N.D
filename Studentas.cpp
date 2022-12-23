#include "Studentas.h"
float Studentas::skaiciuok() {

    for (float paz : nd_) {
        GalutPaz += paz;
    }
    GalutPaz /= 5.0f;
    GalutPaz = GalutPaz * 0.4f + Egz * 0.6f;
    return GalutPaz;
}