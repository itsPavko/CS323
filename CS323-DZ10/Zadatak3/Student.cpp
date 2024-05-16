#include "Student.h"

Student::Student()
{
}

Student::Student(const string& ime, const string& prezime, const string& indeks) {
	this->ime = ime;
	this->prezime = prezime;
	this->indeks = indeks;
}

void Student::info() {
	cout << "Ja sam student." << endl;
}
