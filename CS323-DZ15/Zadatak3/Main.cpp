#include <iostream>
#include <array>

using namespace std;

int poslednjaPojava(const std::array<double, 10>& niz, double x) {
    int indeks = -1;
    int trenutniIndeks = 0;

    for (const auto& broj : niz) {
        if (broj == x) {
            indeks = trenutniIndeks;
        }
        trenutniIndeks++;
    }

    return indeks;
}

int main() {
    array<double, 10> niz;
    double x;

    cout << "Unesite 10 realnih brojeva:" << endl;
    for (auto& broj : niz) {
        cin >> broj;
    }

    cout << "Unesite realan broj x:" << :endl;
    cin >> x;

    int rezultat = poslednjaPojava(niz, x);

    if (rezultat == -1) {
        cout << "Broj " << x << " se ne pojavljuje u nizu." << endl;
    }
    else {
        cout << "Poslednja pojava broja " << x << " je na indeksu " << rezultat << "." << endl;
    }

    return 0;
}