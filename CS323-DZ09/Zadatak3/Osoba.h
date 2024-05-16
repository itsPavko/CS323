#pragma once
#include <string>
#include <iostream>

using namespace std;

class Osoba {
private:
    string ime;
    string adresa;
    int starost;
    static int brojObjekata;

public:
    Osoba();
    Osoba(const string& ime, const string& adresa, int starost);
    ~Osoba();

    static int getBrojObjekata();

    string getIme() const;
    void setIme(const string& ime);
    string getAdresa() const;
    void setAdresa(const string& adresa);
    int getStarost() const;
    void setStarost(int starost);

    friend void postaviBrojObjekata(int broj);
    friend istream& operator>>(istream& is, Osoba& osoba);
    friend ostream& operator<<(ostream& os, const Osoba& osoba);

    bool operator<(const Osoba& druga) const;
    bool operator>(const Osoba& druga) const;
    bool operator==(const Osoba& druga) const;
};

