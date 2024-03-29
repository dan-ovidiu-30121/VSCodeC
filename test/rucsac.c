#include <stdio.h>
#include <stdlib.h>

// Structura pentru a reprezenta un obiect
typedef struct {
    int weight;  // Greutatea obiectului
    int profit;  // Câștigul obținut prin transportul obiectului
    float efficiency;  // Eficiența de transport a obiectului
} Object;

// Funcție pentru compararea a două obiecte în funcție de eficiența de transport
int compare(const void *a, const void *b) {
    const Object *object1 = (const Object *)a;
    const Object *object2 = (const Object *)b;

    if (object1->efficiency > object2->efficiency) {
        return -1;  // Sortare descrescătoare
    } else if (object1->efficiency < object2->efficiency) {
        return 1;
    } else {
        return 0;
    }
}

// Funcție pentru a rezolva problema rucsacului și a determina obiectele de transport pentru câștig maxim
void knapsack(int n, Object *objects, int capacity) {
    int totalProfit = 0;  // Câștigul total inițializat cu 0
    int remainingCapacity = capacity;  // Greutatea rămasă de încărcat inițializată cu capacitatea maximă a rucsacului

    // Sortăm obiectele în ordinea descrescătoare a eficienței de transport
    qsort(objects, n, sizeof(Object), compare);

    // Parcurgem obiectele și le încărcăm în rucsac în ordinea descrescătoare a eficienței
    for (int i = 0; i < n; i++) {
        if (remainingCapacity >= objects[i].weight) {
            // Obiectul încape în totalitate în rucsac
            remainingCapacity -= objects[i].weight;
            totalProfit += objects[i].profit;
            printf("1 ");  // Semnifică încărcarea în totalitate a obiectului în rucsac
        } else {
            // Obiectul nu încape în totalitate în rucsac
            float fraction = (float)remainingCapacity / objects[i].weight;  // Procentul din obiect care poate fi transportat
            totalProfit += fraction * objects[i].profit;
            remainingCapacity = 0;
            printf("%.2f ", fraction);  // Tipărim procentul din obiect care s-a încărcat în rucsac
        }
    }

    printf("\nCâștigul maxim obținut: %d\n", totalProfit);  // Afisăm câștigul total obținut
}

int main() {
    /*int n, capacity;
    printf("Introduceți numărul de obiecte și capacitatea maximă a rucsacului: ");
    scanf("%d %d", &n, &capacity);

    // Alocare dinamică pentru n obiecte
    Object *objects = (Object *)malloc(n * sizeof(Object));

    // Citirea detaliilor despre obiecte
    for (int i = 0; i < n; i++) {
        printf("Introduceți greutatea și câștigul obiectului %d: ", i + 1);
        scanf("%d %d", &objects[i].weight, &objects[i].profit);
        objects[i].efficiency = (float)objects[i].profit / objects[i].weight;  // Calculăm eficiența de transport
    }

    // Rezolvăm problema rucsacului
    knapsack(n, objects, capacity);

    // Eliberăm memoria alocată dinamic
    free(objects);*/
    int x = 14^84;
    printf("%d",x);

    return 0;
}
