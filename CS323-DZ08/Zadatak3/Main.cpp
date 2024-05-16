#include "Student.h"

int main() {
    Student nizStudenata[3];

    for (int i = 0; i < 3; i++) {
        nizStudenata[i].unosPodataka();
    }

    int indeksNajboljeg = 0;
    for (int i = 1; i < 3; i++) {
        if (nizStudenata[i].getProsek() > nizStudenata[indeksNajboljeg].getProsek()) {
            indeksNajboljeg = i;
        }
    }

    nizStudenata[indeksNajboljeg].ispisPodataka();

    return 0;
}