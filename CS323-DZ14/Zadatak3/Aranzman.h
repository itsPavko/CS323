#pragma once
#include <iostream>
#include <string>

using namespace std;


class Aranzman {
public:
    string imeAgencije;
    string imeHotela;
    string mesto;
    int brojNocenja;
    double cena;

    Aranzman(const string& agencija, const string& hotel, const string& mesto, int nocenja, double cena)
        : imeAgencije(agencija), imeHotela(hotel), mesto(mesto), brojNocenja(nocenja), cena(cena) {}
};

