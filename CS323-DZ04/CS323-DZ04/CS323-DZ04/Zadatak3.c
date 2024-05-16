#include <stdio.h>

void calculateNZD(int number1, int number2, int* nzd) {
    int min = (number1 < number2) ? number1 : number2;
    int max = (number1 > number2) ? number1 : number2;

    for (int i = min; i > 0; i--) {
        if (max % i == 0 && min % i == 0) {
            *nzd = i;
            return;
        }
    }
}

void main() {

    int number1 = 8;
    int number2 = 12;
    int nzd;

    calculateNZD(number1, number2, &nzd);

    printf("NZD za date brojeve je: %d", nzd);
}