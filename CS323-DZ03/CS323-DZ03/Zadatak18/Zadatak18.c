#include <stdio.h>
#include <string.h>

void shortenString(char* stringArray, int p) {
    if (strlen(stringArray) > p) {
        stringArray[p] = '\0'; 
    }
}

void main() {

    char stringArray[] = {"Ovo je tekst za testiranje zadatka"};
    int p;

    printf("Unesite broj prvih karaktera koji zelite da se prikaze: ");
    scanf("%d", &p);

    shortenString(stringArray, p);

    printf("Skraceni tekst: %s\n", stringArray);
}