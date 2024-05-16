#include "Osoba.h"

int main() {
    Osoba nizOsoba[3];

    for (int i = 0; i < 3; i++) {
        nizOsoba[i].unosPodataka();
    }

    Osoba najmladjaOsoba = nizOsoba[0];
    Osoba najstarijaOsoba = nizOsoba[0];

    for (int i = 1; i < 3; i++) {
        if (nizOsoba[i].getStarost() < najmladjaOsoba.getStarost()) {
            najmladjaOsoba = nizOsoba[i];
        }
        if (nizOsoba[i].getStarost() > najstarijaOsoba.getStarost()) {
            najstarijaOsoba = nizOsoba[i];
        }
    }

    cout << "Najmladja osoba: " << najmladjaOsoba.getIme() << " " << najmladjaOsoba.getAdresa() << " " << najmladjaOsoba.getStarost() << endl;
    cout << "Najstarija osoba: " << najstarijaOsoba.getIme() << " " << najstarijaOsoba.getAdresa() << " " << najstarijaOsoba.getStarost() << endl;

}