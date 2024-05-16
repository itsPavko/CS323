#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double re;
    double im;
} Complex;

Complex conjugate(Complex z) {
    z.im = -z.im;
    return z;
}

void main() {
    int n;

    printf("Unesite broj kompleksnih brojeva u nizu: ");
    scanf_s("%d", &n);

    Complex* array = malloc(n * sizeof(Complex));

    printf("Unesite kompleksne brojeve u formatu re, im: ");
    for (int i = 0; i < n; i++) {
        scanf_s("%lf, %lf", &array[i].re, &array[i].im);
    }

    printf("Konjugovano kompleksni brojevi: ");
    for (int i = 0; i < n; i++) {
        Complex z = conjugate(array[i]);
        printf("(%.2lf, %.2lf) ", z.re, z.im);
    }
    printf("\n");

    free(array);
}