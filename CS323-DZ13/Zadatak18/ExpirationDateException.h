#pragma once
#include <iostream>

using namespace std;

class ExpirationDateException : exception {
public:
    virtual const char* expirationDateExc() const throw() {
        return "Rok trajanja proizvoda nije validan.";
    }
};

