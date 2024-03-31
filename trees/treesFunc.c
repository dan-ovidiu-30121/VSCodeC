#include "trees.h"
#include <stdio.h>
#include <stdlib.h>
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

treeNode* invertTree(treeNode* root) {
    if(root == NULL)
      return NULL;
    treeNode *node = root->left;
    root->left = root->right;
    root->right = node;
    
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
bool isMirror(treeNode *node1, treeNode *node2)
{
    if(node1 == NULL && node2 == NULL)
      return true;
    if(node1 == NULL || node2 == NULL)
      return false;
    return ((node1->value==node2->value)&&isMirror(node1->left,node2->right)&&isMirror(node1->right,node2->left));
}
bool isSymmetric(treeNode* root) {
    if(root == NULL)
      return NULL;
    return isMirror(root->left,root->right);
}