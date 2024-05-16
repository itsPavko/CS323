#include "BachlorStudent.h"

BachelorStudent::BachelorStudent(const string& ime, const string& prezime, const string& indeks, const string& smer) {
	this->ime = ime;
	this->prezime = prezime;
	this->indeks = indeks;
	this->smer = smer;
}

void BachelorStudent::info() {
	cout << "Ja sam student na smeru " << smer << "." << endl;
}
