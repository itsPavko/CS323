#pragma once
#include <iostream>
#include <string>
#include "Zaposleni.h"

using namespace std;

class Lekar : public Zaposleni {

private:
    string fakultet;

public:
    Lekar(const string& ime, const string& prezime, const string& adresa,
        const string& telefon, int godiste, const string& datumRodjenja,
        const string& fakultet)
        : Zaposleni(ime, prezime, adresa, telefon, godiste, datumRodjenja), fakultet(fakultet) {}

    void Info() const override {
        Zaposleni::Info();
        cout << "Fakultet: " << fakultet << endl;
    }
};


