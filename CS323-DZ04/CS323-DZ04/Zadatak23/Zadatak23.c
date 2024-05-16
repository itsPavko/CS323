#include <stdio.h>
#include <string.h>

void printDifferentVariationsOfString(char* array, int k, int p) {
    int i;

    printf("Prvih %d karaktera: ", k);

    for (i = 0; i < k; i++) {
        printf("%c", *(array + i));
    }

    printf("\n");

    int length = strlen(array);

    printf("Poslednjih %d karaktera: ", k);

    for (i = length - k; i < length; i++) {
        printf("%c", *(array + i));
    }

    printf("\n");
    printf("Karakteri od pozicije %d na duzinu %d: ", p, k);

    for (i = p; i < p + k && *(array + i) != '\0'; i++) {
        printf("%c", *(array + i));
    }
    printf("\n");
}

void main() {
    char array[] = {"Tekst za testiranje"};
    int k = 8;
    int p = 4;

    printDifferentVariationsOfString(array, k, p);
}