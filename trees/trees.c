#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct treeNode
{
    int value;
    struct treeNode *left, *right;
} treeNode;

treeNode *createNode(int value)
{
    treeNode *result = malloc(sizeof(treeNode));
    if (result != NULL)
    {
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }
    return result;
}
void printtabs(int numtabs)
{
    for (int i = 0; i < numtabs; i++)
    {
        printf("\t");
    }
}
void printTree(treeNode *root, int level)
{
    if (root == NULL)
    {
        printtabs(level);
        printf("---<empty>---\n");
        return;
    }
    printtabs(level);
    printf("Value = %d\n", root->value);
    printtabs(level);
    printf("left\n");

    printTree(root->left, level + 1);
    printtabs(level);

    printf("right\n");
    printTree(root->right, level + 1);
    printtabs(level);
}
bool isSameTree(treeNode *p, treeNode *q)
{
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL)
        return false;
    if (p->value != q->value)
        return false;
    return (isSameTree(p->right, q->right) && isSameTree(p->left, q->left));
}
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
        printf("Same trees");
    else
        printf("Different trees");

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