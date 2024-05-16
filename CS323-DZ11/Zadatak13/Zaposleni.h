#pragma once
#include <iostream>
#include <string>

using namespace std;

class Zaposleni {

protected:
    string ime;
    string prezime;
    string adresa;
    string telefon;
    int godiste;
    string datumRodjenja;

public:
    Zaposleni(const string& ime, const string& prezime, const string& adresa,
        const string& telefon, int godiste, const string& datumRodjenja)
        : ime(ime), prezime(prezime), adresa(adresa), telefon(telefon),
        godiste(godiste), datumRodjenja(datumRodjenja) {}

    virtual void Info() const {
        cout << "Ime: " << ime << endl;
        cout << "Prezime: " << prezime << endl;
        cout << "Adresa: " << adresa << endl;
        cout << "Telefon: " << telefon << endl;
        cout << "Godiste: " << godiste << endl;
        cout << "Datum rodjenja: " << datumRodjenja << endl;
    }
};

