#pragma once
#include <iostream>
#include <string>

using namespace std;

class Osoba {
private:
    string ime;
    string adresa;
    int starost;

public:
    Osoba();
    Osoba(string ime, string adresa, int starost);
    Osoba(Osoba& o);

    string getIme();
    void setIme(string ime);
    string getAdresa();
    void setAdresa(string adresa);
    int getStarost();
    void setStarost(int starost);

    void unosPodataka();
    void ispisPodataka();

    ~Osoba();
};

