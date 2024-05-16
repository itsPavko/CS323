#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

struct Aranzman {
    char imeAgencije[MAX_LEN];
    char imeHotela[MAX_LEN];
    char mesto[MAX_LEN];
    int brojNocenja;
    float cena;
};

int main(int argc, char* argv[]) {
    
    FILE* fajl = fopen(argv[1], "r");

    if (!fajl) {
        printf("Neuspesno otvaranje datoteke.\n");
        return 1;
    }

    int brojAranzmana;
    fscanf(fajl, "%d\n", &brojAranzmana);

    struct Aranzman* aranzmani = (struct Aranzman*)malloc(brojAranzmana * sizeof(struct Aranzman));

    if (!aranzmani) {
        printf("Neuspesna alokacija memorije.\n");
        fclose(fajl);
        return 1;
    }

    for (int i = 0; i < brojAranzmana; i++) {
        fscanf(fajl, "%s %s %s %d %f\n", aranzmani[i].imeAgencije, aranzmani[i].imeHotela, aranzmani[i].mesto,
            &aranzmani[i].brojNocenja, &aranzmani[i].cena);
    }

    int najjeftinijiIndeks = 0;
    for (int i = 1; i < brojAranzmana; i++) {
        if (aranzmani[i].cena < aranzmani[najjeftinijiIndeks].cena) {
            najjeftinijiIndeks = i;
        }
    }

    printf("Najjeftiniji aranzman:\n");
    printf("Ime agencije: %s\n", aranzmani[najjeftinijiIndeks].imeAgencije);
    printf("Ime hotela: %s\n", aranzmani[najjeftinijiIndeks].imeHotela);
    printf("Mesto: %s\n", aranzmani[najjeftinijiIndeks].mesto);
    printf("Broj nocenja: %d\n", aranzmani[najjeftinijiIndeks].brojNocenja);
    printf("Cena aranzmana: %.2f\n", aranzmani[najjeftinijiIndeks].cena);

    free(aranzmani);
    fclose(fajl);
    return 0;
}