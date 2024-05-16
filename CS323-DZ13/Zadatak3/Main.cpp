#include <iostream>
#include "Calculator.h"

using namespace std;

int main() {
    int a, b;

    cout << "Unesite prvi broj: ";
    cin >> a;
    cout << "Unesite drugi broj: ";
    cin >> b;

    try {
        Calculator calculator(a, b);
        float result = calculator.divide();
        cout << "Rezultat deljenja: " << result << endl;
    }
    catch (const EvenNumberException& e) {
        cout << "Greska: " << e.evenNumberExc() << endl;
    }
    catch (const DivideWithZeroException& e) {
        cout << "Greska: " << e.divideWithZeroExc() << endl;
    }

    return 0;
}