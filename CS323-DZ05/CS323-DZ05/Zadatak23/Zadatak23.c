#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void separateArray(int* arrayA, int n, int** arrayB, int* nOfB, int** arrayC, int* nOfC) {
	*nOfB = 0;
	*nOfC = 0;

	for (int i = 0; i < n; i++) {
		if (arrayA[i] < 0) (*nOfB)++;
		else (*nOfC)++;
	}

	*arrayB = (int*)malloc((*nOfB) * sizeof(int));
	*arrayC = (int*)malloc((*nOfC) * sizeof(int));

	int indexB = 0;
	int indexC = 0;

	for (int i = 0; i < n; i++) {
		if (arrayA[i] < 0) (*arrayB)[indexB++] = arrayA[i];
		else (*arrayC)[indexC++] = arrayA[i];
	}
}

void main() {
	int n = 10;
	int* arrayA = (int*)malloc(n * sizeof(int));
	int* arrayB;
	int* arrayC;
	int nOfB;
	int nOfC;

	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		arrayA[i] = rand() % 201 - 100;
	}

	separateArray(arrayA, n, &arrayB, &nOfB, &arrayC, &nOfC);

	printf("Niz A: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arrayA[i]);
	}

	printf("\nNiz B: ");
	for (int i = 0; i < nOfB; i++) {
		printf("%d ", arrayB[i]);
	}

	printf("\nNiz C: ");
	for (int i = 0; i < nOfC; i++) {
		printf("%d ", arrayC[i]);
	}

	free(arrayA);
	free(arrayB);
	free(arrayC);
}
