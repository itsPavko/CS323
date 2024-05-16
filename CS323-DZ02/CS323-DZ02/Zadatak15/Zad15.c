#include <stdio.h>
#include <stdlib.h>

void main() {

	srand(time(0));

	int number, counter = 0;

	while (1) {
		number = rand() % 1000;
		printf("Generisan broj: %d\n", number);
		counter++;

		if (number == 500) {
			printf("Generisan je broj 500");
			break;
		}
		else if (counter > 1000) {
			printf("Brojac je presao 1000 pokusaja");
			break;
		}
	}
}