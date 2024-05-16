#pragma once
#include "Student.h"

class BachelorStudent : public Student {
private:
    string smer;

public:
    BachelorStudent(const string& ime, const string& prezime, const string& indeks, const string& smer);
    void info();
};
