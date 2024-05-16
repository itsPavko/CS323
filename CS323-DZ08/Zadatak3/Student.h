#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string ime;
    string prezime;
    string smer;
    double prosek;

public:
    Student();
    Student(string ime, string prezime, string smer, double prosek);
    Student(Student& other);

    void setIme(string ime);
    string getIme();
    void setPrezime(string prezime);
    string getPrezime();
    void setSmer(string smer);
    string getSmer();
    void setProsek(double prosek);
    double getProsek();

    void unosPodataka();
    void ispisPodataka();

    ~Student();
};


