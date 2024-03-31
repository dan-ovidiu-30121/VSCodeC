#ifndef TREE_FUNCTIONS_H
#define TREE_FUNCTIONS_H

#include <stdbool.h>

typedef struct treeNode
{
    int value;
    struct treeNode *left, *right;
} treeNode;

treeNode *createNode(int value);
void printtabs(int numtabs);
void printTree(treeNode *root, int level);
bool isSameTree(treeNode *p, treeNode *q);
treeNode* invertTree(treeNode* root);

#endif 
