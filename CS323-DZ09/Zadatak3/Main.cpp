#include <iostream>
#include "Osoba.h"

using namespace std;

const int BROJ_OSOBA = 5;

int main() {
	Osoba osobe[BROJ_OSOBA];

	for (int i = 0; i < BROJ_OSOBA; i++) {
		cout << "Unesite podatke za osobu " << i + 1 << endl;
		cin >> osobe[i];
	}

	Osoba najmladja = osobe[0];
	Osoba najstarija = osobe[0];

	for (int i = 1; i < BROJ_OSOBA; i++) {
		if (osobe[i] < najmladja) {
			najmladja = osobe[i];
		}

		if (osobe[i] > najstarija) {
			najstarija = osobe[i];
		}
	}

	cout << "Najmladja osoba: " << najmladja << endl;
	cout << "Najstarija osoba: " << najstarija << endl;

	cout << "Osobe koje se zovu Petar:" << endl;
	for (int i = 0; i < BROJ_OSOBA; i++) {
		if (osobe[i].getIme() == "Petar") {
			cout << osobe[i] << endl;
		}
	}

	cout << "Trenutni broj kreiranih objekata: " << Osoba::getBrojObjekata() << endl;

	return 0;
}