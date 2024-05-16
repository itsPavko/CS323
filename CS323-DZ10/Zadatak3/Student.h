#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student {
protected:
    string ime;
    string prezime;
    string indeks;

public:
    Student();
    Student(const string& ime, const string& prezime, const string& indeks);
    void info();
};

