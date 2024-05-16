#include "Osoba.h"

int Osoba::brojObjekata = 0;

Osoba::Osoba() {
    brojObjekata++;
}

Osoba::Osoba(const string& ime, const string& adresa, int starost) {
    this->ime = ime;
    this->adresa = adresa;
    this->starost = starost;
    brojObjekata++;
}

Osoba::~Osoba() {
    brojObjekata--;
}

int Osoba::getBrojObjekata() {
    return brojObjekata;
}

string Osoba::getIme() const {
    return ime;
}

void Osoba::setIme(const string& ime) {
    this->ime = ime;
}

string Osoba::getAdresa() const {
    return adresa;
}

void Osoba::setAdresa(const string& adresa) {
    this->adresa = adresa;
}

int Osoba::getStarost() const {
    return starost;
}

void Osoba::setStarost(int starost) {
    this->starost = starost;
}

void postaviBrojObjekata(int broj) {
    Osoba::brojObjekata = broj;
}

istream& operator>>(istream& is, Osoba& osoba) {
    cout << "Unesite ime: ";
    getline(is >> ws, osoba.ime);
    cout << "Unesite adresu: ";
    getline(is >> ws, osoba.adresa);
    cout << "Unesite starost: ";
    is >> osoba.starost;
    return is;
}

ostream& operator<<(ostream& os, const Osoba& osoba) {
    os << "Ime: " << osoba.ime << ", Adresa: " << osoba.adresa << ", Starost: " << osoba.starost;    
    return os;
}

bool Osoba::operator<(const Osoba& druga) const {
    return starost < druga.starost;
}

bool Osoba::operator>(const Osoba& druga) const {
    return starost > druga.starost;
}

bool Osoba::operator==(const Osoba& druga) const {
    return ime == druga.ime;
}