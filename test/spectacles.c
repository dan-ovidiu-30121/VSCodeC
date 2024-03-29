#include <stdio.h>
#include <stdlib.h>

// Structura pentru a reprezenta un spectacol
typedef struct {
    int start; // Ora de început a spectacolului
    int end;   // Ora de sfârșit a spectacolului
} Spectacle;

// Funcție pentru compararea a două spectacole în funcție de ora de sfârșit
int compare(const void *a, const void *b) {
    const Spectacle *spectacle1 = (const Spectacle *)a;
    const Spectacle *spectacle2 = (const Spectacle *)b;

    return spectacle1->end - spectacle2->end;
}

// Funcție pentru a găsi programul optim
void findOptimalSchedule(Spectacle *spectacles, int n) {
    // Sortăm spectacolele după ora de sfârșit
    qsort(spectacles, n, sizeof(Spectacle), compare);

    // Initializăm primul spectacol ca fiind inclus în programul optim
    int currentEnd = spectacles[0].end;
    printf("Programul optim include spectacolul cu ora [%d, %d]\n", spectacles[0].start, spectacles[0].end);

    // Parcurgem celelalte spectacole și verificăm dacă se potrivesc în programul optim
    for (int i = 1; i < n; i++) {
        if (spectacles[i].start >= currentEnd) {
            printf("Programul optim include spectacolul cu ora [%d, %d]\n", spectacles[i].start, spectacles[i].end);
            currentEnd = spectacles[i].end;
        }
    }
}

int main() {
    int n;
    printf("Introduceți numărul de spectacole: ");
    scanf("%d", &n);

    // Alocare dinamică pentru n spectacole
    Spectacle *spectacles = (Spectacle *)malloc(n * sizeof(Spectacle));

    // Citirea detaliilor despre spectacole
    for (int i = 0; i < n; i++) {
        printf("Introduceți ora de început și ora de sfârșit pentru spectacolul %d: ", i + 1);
        scanf("%d %d", &spectacles[i].start, &spectacles[i].end);
    }

    // Găsirea programului optim
    findOptimalSchedule(spectacles, n);

    // Eliberarea memoriei alocate dinamic
    free(spectacles);

    return 0;
}
