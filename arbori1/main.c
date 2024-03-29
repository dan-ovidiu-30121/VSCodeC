#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct tip_nod
{
    int nr; /*informaţie */
    struct tip_nod *stg, *dr;
} TIP_NOD;
TIP_NOD *rad;
void preordine(TIP_NOD *p, int nivel)
{
    int i;
    if (p != 0)
    {
        for (i = 0; i <= nivel; i++)
            printf(" ");
        printf("%2d\n", p->nr);
        preordine(p->stg, nivel + 1);
        preordine(p->dr, nivel + 1);
    }
}
void inordine(TIP_NOD *p, int nivel)
{
    int i;
    if (p != 0)
    {
        inordine(p->stg, nivel + 1);
        for (i = 0; i <= nivel; i++)
            printf(" ");
        printf("%2d\n", p->nr);
        inordine(p->dr, nivel + 1);
    }
}
void postordine(TIP_NOD *p, int nivel)
{
    int i;
    if (p != 0)
    {
        postordine(p->stg, nivel + 1);
        postordine(p->dr, nivel + 1);
        for (i = 0; i <= nivel; i++)
            printf(" ");
        printf("%2d\n", p->nr);
    }
}
TIP_NOD *constructie()
{
    TIP_NOD *p;
    int inf, n;
    n = sizeof(TIP_NOD);
    printf("\nIntroduceti Inf.din nod inf=");
    scanf("%d", &inf);
    if (inf == 0)
        return 0;
    else
    {
        p = (TIP_NOD *)malloc(n);
        p->nr = inf;
        p->stg = constructie();
        p->dr = constructie();
    }
    return p;
}
int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(TIP_NOD *node) {
    if (node == NULL) {
        return 0;
    } else {
        int leftHeight = height(node->stg);
        int rightHeight = height(node->dr);

        return 1 + max(leftHeight, rightHeight);
    }
}
void main(void)
{
    rad = constructie();
    printf("\nVIZITAREA IN PREORDINE\n");
    preordine(rad, 0);
    getch();
    printf("\nVIZITAREA IN INORDINE\n");
    inordine(rad, 0);
    getch();
    printf("VIZITAREA IN POSTORDINE\n");
    postordine(rad, 0);
    printf("Inaltimea arborelui este: %d",height(rad));
    getch();
}
