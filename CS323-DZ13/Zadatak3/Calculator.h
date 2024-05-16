#pragma once
#include "DivideWithZeroException.h"
#include "EvenNumberException.h"

class Calculator {
private:
    int a;
    int b;
    float result;

public:
    Calculator(int a, int b) : a(a), b(b), result(0.0f) {}

    float divide() {
        if (a % 2 == 0 || b % 2 == 0) {
            throw EvenNumberException();
        }

        if (b == 0) {
            throw DivideWithZeroException();
        }

        result = static_cast<float>(a) / b;
        return result;
    }
};

