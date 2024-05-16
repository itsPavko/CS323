#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Aranzman.h"

using namespace std;


int main() {
    string imeDatoteke;
    cout << "Unesite ime tekstualne datoteke sa podacima o aranzmanima: ";
    cin >> imeDatoteke;

    ifstream datoteka(imeDatoteke);
    if (!datoteka.is_open()) {
        cout << "Greska pri otvaranju datoteke." << endl;
        return 1;
    }

    int brojAranzmana;
    datoteka >> brojAranzmana;

    vector<Aranzman> aranzmani;
    for (int i = 0; i < brojAranzmana; i++) {
        string agencija, hotel, mesto;
        int nocenja;
        double cena;

        datoteka >> agencija >> hotel >> mesto >> nocenja >> cena;
        aranzmani.push_back(Aranzman(agencija, hotel, mesto, nocenja, cena));
    }

    datoteka.close();

    if (aranzmani.empty()) {
        cout << "Nema dostupnih aranzmana." << endl;
        return 0;
    }

    Aranzman najjeftiniji = aranzmani[0];
    for (const Aranzman& aranzman : aranzmani) {
        if (aranzman.cena < najjeftiniji.cena) {
            najjeftiniji = aranzman;
        }
    }

    cout << "Najjeftiniji aranzman:" << endl;
    cout << "Agencija: " << najjeftiniji.imeAgencije << endl;
    cout << "Hotel: " << najjeftiniji.imeHotela << endl;
    cout << "Mesto: " << najjeftiniji.mesto << endl;
    cout << "Broj nocenja: " << najjeftiniji.brojNocenja << endl;
    cout << "Cena: " << najjeftiniji.cena << endl;

    return 0;
}