#include <string>
#include <iostream>
#include "Product.h"

using namespace std;

int main() {

    string name;
    float price;
    int expirationDate;

    cout << "Unesite ime proizvoda: ";
    getline(cin, name);

    cout << "Unesite cenu proizvoda: ";
    cin >> price;

    cout << "Unesite rok trajanja proizvoda: ";
    cin >> expirationDate;

    try {
        Product product(name, price, expirationDate);
        cout << "Podaci o proizvodu:" << endl;
        cout << "Ime: " << product.getName() << endl;
        cout << "Cena: " << product.getPrice() << endl;
        cout << "Rok trajanja: " << product.getExpirationDate() << " dana" << endl;
    }
    catch (const ExpirationDateException& e) {
        cout << "Greska: " << e.expirationDateExc() << endl;
    }

    return 0;
}