#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <stack>

#include "Lekar.h"
#include "Zaposleni.h"

using namespace std;

void zadatak1() {
    vector<Zaposleni> zaposleni;

    // Kreirati vektor od 5 proizvoljnih objekata klase Zaposleni
    zaposleni.push_back(Zaposleni("Marko", "Markovic", "Adresa 1", "123456", 1990, "01.01.1990"));
    zaposleni.push_back(Zaposleni("Jovan", "Jovanovic", "Adresa 2", "654321", 1985, "01.01.1985"));
    zaposleni.push_back(Zaposleni("Ana", "Anic", "Adresa 3", "987654", 1995, "01.01.1995"));
    zaposleni.push_back(Zaposleni("Milica", "Milicic", "Adresa 4", "456789", 1988, "01.01.1988"));
    zaposleni.push_back(Zaposleni("Petar", "Petrovic", "Adresa 5", "321654", 1992, "01.01.1992"));

    // Ubaciti novi objekat na 3. mesto
    zaposleni.insert(zaposleni.begin() + 2, Zaposleni("Novi", "Objekat", "Nova adresa", "999999", 2000, "01.01.2000"));

    // Obrisati poslednji objekat
    zaposleni.pop_back();

    for (const auto& zaposlen : zaposleni) {
       cout << zaposlen.ime << " " << zaposlen.prezime << " " << zaposlen.adresa << " " << zaposlen.telefon << " " << zaposlen.godiste << " " << zaposlen.datumRodjenja << endl;
    }
}

void zadatak2() {
    vector<Zaposleni> zaposleni;

    Zaposleni z1("Ime1", "Prezime1", "Adresa1", "Telefon1", 1990, "01.01.1990");
    zaposleni.push_back(z1);

    Zaposleni z2("Ime2", "Prezime2", "Adresa2", "Telefon2", 1995, "01.01.1995");
    zaposleni.push_back(z2);

    // Ispitati da li se objekat z2 nalazi u vektoru
    vector<Zaposleni>::iterator it = find(zaposleni.begin(), zaposleni.end(), z2);

    // Ispisati na kraju poruku o statusu
    if (it != zaposleni.end()) {
        cout << "Objekat je pronađen." << endl;
    }
    else {
        cout << "Objekat nije pronađen." << endl;
    }
}

void zadatak3() {
    ifstream inputFile("ulaz.txt");
    stack<Zaposleni> zaposleniStack;

    if (!inputFile.is_open()) {
        cout << "Error: Unable to open input file." << endl;
        return;
    }

    string ime, prezime, adresa, telefon, datumRodjenja;
    int godiste;
    while (inputFile >> ime >> prezime >> adresa >> telefon >> godiste >> datumRodjenja) {
        Zaposleni zaposlen(ime, prezime, adresa, telefon, godiste, datumRodjenja);
        zaposleniStack.push(zaposlen);
    }

    inputFile.close();

    ofstream outputFile("izlaz.txt");
    if (!outputFile.is_open()) {
        cout << "Error: Unable to open output file." << endl;
        return;
    }

    // Ispisivanje objekata u inverznom poretku u izlazni fajl
    while (!zaposleniStack.empty()) {
        const Zaposleni& zaposlen = zaposleniStack.top();
        outputFile << zaposlen.ime << " " << zaposlen.prezime << " " << zaposlen.adresa << " " << zaposlen.telefon << " " << zaposlen.godiste << " " << zaposlen.datumRodjenja << endl;
        zaposleniStack.pop();
    }

    outputFile.close();
}


int main() {
    zadatak1();
    zadatak2();
    zadatak3();

    return 0;
}