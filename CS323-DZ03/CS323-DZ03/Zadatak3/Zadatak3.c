#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {

    int array[20];
    int sum = 0;
    int count = 0;

    srand(time(NULL));

    for (int i = 0; i < 20; i++) {
        array[i] = rand() % 10;
    }

    for (int i = 0; i < 20; i++) {
        if (array[i] % 2 == 0) {
            sum += array[i];
        }
        if (array[i] == 0) {
            count++;
        }
    }

    printf("Niz: ");

    for (int i = 0; i < 20; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
    printf("Suma parnih brojeva: %d", sum);
    printf("\n");
    printf("Broj nula u nizu: %d\n", count);

}