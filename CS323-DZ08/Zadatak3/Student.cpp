#include "Student.h"

Student::Student() {
	this->ime = "";
	this->prezime = "";
	this->smer = "";
	this->prosek = 0.0;
}

Student::Student(string ime, string prezime, string smer, double prosek) {
	this->ime = ime;
	this->prezime = prezime;
	this->smer = smer;
	this->prosek = prosek;
}

Student::Student(Student& other) {
	this->ime = other.ime;
	this->prezime = other.prezime;
	this->smer = other.smer;
	this->prosek = other.prosek;
}

void Student::setIme(string ime) {
	this->ime = ime;
}

string Student::getIme() {
	return this->ime;
}

void Student::setPrezime(string prezime) {
	this->prezime = prezime;
}

string Student::getPrezime() {
	return this->prezime;
}

void Student::setSmer(string smer) {
	this->smer = smer;
}

string Student::getSmer() {
	return this->smer;
}

void Student::setProsek(double prosek) {
	this->prosek = prosek;
}

double Student::getProsek() {
	return this->prosek;
}

void Student::unosPodataka() {
	cout << "Unesite ime studenta: ";
	cin >> ime;
	cout << "Unesite prezime studenta: ";
	cin >> prezime;
	cout << "Unesite smer studenta: ";
	cin >> smer;
	cout << "Unesite prosek studenta: ";
	cin >> prosek;
}

void Student::ispisPodataka() {
	cout << "Najbolji prosek ima:" << endl;
	cout << "Ime i prezime: " << ime << " " << prezime << endl;
	cout << "Smer: " << smer << endl;
	cout << "Prosek: " << prosek << endl;
}

Student::~Student() {
	std::cout << "Objekat je unisten" << std::endl;
}
