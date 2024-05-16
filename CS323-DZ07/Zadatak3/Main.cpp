#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    char c;

    cout << "Unesite jedan karakter: ";
    cin >> c;
    cout << setw(10) << c << setw(15) << static_cast<int>(c) << endl;

    for (int i = 1; i <= 3; i++) {
        char next_c = static_cast<char>(c + i);
        cout << setw(10) << next_c << setw(15) << static_cast<int>(next_c) << endl;
    }

    return 0;
}