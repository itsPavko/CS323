#include <iostream>
#include "Lekar.h"
using namespace std;

int main() {
    Zaposleni zaposleni("Pera", "Peric", "Adresa 123", "123456789", 1990, "01.01.1990");
    Lekar lekar("Mika", "Mikic", "Adresa 456", "987654321", 1985, "01.01.1985", "Medicinski fakultet");

    cout << "Informacije o zaposlenom:" << endl;
    zaposleni.Info();

    cout << "Informacije o lekaru:" << endl;
    lekar.Info();

    return 0;
}