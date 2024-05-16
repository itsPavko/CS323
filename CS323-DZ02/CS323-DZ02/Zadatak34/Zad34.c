#include <stdio.h>

void printShape(int n) {
    int i, j;

    for (i = n; i > 0; i--) {
        for (j = i - 1; j < n; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void main() {
    int n;

    printf("Unesite broj n: ");
    scanf("%d", &n);

    printShape(n);
}