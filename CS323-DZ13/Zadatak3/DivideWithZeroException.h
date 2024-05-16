#pragma once

#include <iostream>

using namespace std;

class DivideWithZeroException : public exception {
public:
    virtual const char* divideWithZeroExc() const throw() {
        return "Uneti broj je paran.";
    }
};

