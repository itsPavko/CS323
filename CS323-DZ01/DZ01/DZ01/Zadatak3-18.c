#include <stdio.h>

void main() {

    // zadatak 3

   /* int a, b, c;

    printf("Unesite tri broja zaredom: \n");
    scanf("%d %d %d", &a, &b, &c);

    if ((a + b == c) || (a + c == b) || (b + c == a)) {
        printf("Moze\n");
    }
    else {
        printf("Ne moze\n");
    }*/

    // zadatak 18 - multiply by 1.8 (or 9/5) and add 32

    float cells, farenhait;

    printf("Unesite temperaturu u Celsijusima: \n");
    scanf("%f", &cells);

    farenhait = cells * 1.8 + 32;

    printf("Temperatura Farenhajt je = %.2f", farenhait);
}