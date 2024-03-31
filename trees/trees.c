#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "trees.h"
int main()
{
    treeNode *n1 = createNode(10);
    treeNode *n2 = createNode(11);
    treeNode *n3 = createNode(12);
    treeNode *n4 = createNode(13);
    treeNode *n5 = createNode(14);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    treeNode *a1 = createNode(10);
    treeNode *a2 = createNode(11);
    treeNode *a3 = createNode(12);
    treeNode *a4 = createNode(13);
    treeNode *a5 = createNode(14);

    a1->left = a2;
    a1->right = a3;
    a3->left = a4;
    a3->right = a5;
    if (isSameTree(n1, a1) == true)
        printf("Same trees\n");
    else
        printf("Different trees\n");
    invertTree(n1);
    printTree(n1,0);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);

    free(a1);
    free(a2);
    free(a3);
    free(a4);
    free(a5);
    return 0;
}