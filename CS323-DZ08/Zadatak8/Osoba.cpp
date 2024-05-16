#include "Osoba.h"

Osoba::Osoba() {
    this->ime = "";
    this->adresa = "";
    this->starost = 0;
}

Osoba::Osoba(string ime, string adresa, int starost) {
    this->ime = ime;
    this->adresa = adresa;
    this->starost = starost;
}

Osoba::Osoba(Osoba& o) {
    this->ime = o.ime;
    this->adresa = o.adresa;
    this->starost = o.starost;
}

string Osoba::getIme() {
    return this->ime;
}
void Osoba::setIme(string ime) {
    this->ime = ime;
}

string Osoba::getAdresa() {
    return this->adresa;
}
void Osoba::setAdresa(string adresa) {
    this->adresa = adresa;
}

int Osoba::getStarost() {
    return this->starost;
}
void Osoba::setStarost(int starost) {
    this->starost = starost;
}

void Osoba::unosPodataka() {
    cout << "Unesite ime: ";
    cin >> ime;
    cout << "Unesite adresu: ";
    cin >> adresa;
    cout << "Unesite starost: ";
    cin >> starost;
}

void Osoba::ispisPodataka() {
    cout << "Ime: " << this->ime << endl;
    cout << "Adresa: " << this->adresa << endl;
    cout << "Starost: " << this->starost << endl;
}


Osoba::~Osoba() {
    std::cout << "Objekat je unisten" << std::endl;
}
