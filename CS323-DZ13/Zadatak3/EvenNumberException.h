#pragma once
#include <iostream>

using namespace std;

class EvenNumberException : exception {
public:
    virtual const char* evenNumberExc() const throw() {
        return "Deljenje sa nulom nije dozvoljeno.";
    }
};

