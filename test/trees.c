#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct bst
{
    int data;
    struct bst* left;
    struct bst* right;
}bst;
bst *insert(bst **root,int val);
void preorder(bst *root);
void inorder(bst *root);
void postorder(bst *root);
int main()
{
    bst *root = NULL;
    insert(&root,2);
    insert(&root,3);
    insert(&root,1);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    return 0;
}
bst *insert(bst **root,int val)
{
    bst *tmp = (bst*)malloc(sizeof(bst));
    bst *current = *root;
    if(*root == NULL)
    {
        tmp->data = val;
        tmp->left = NULL;
        tmp->right = NULL;
        *root = tmp;
    }
    else
    {
        if(current->data > val)
        {
            current->left = insert(&(current->left),val);
        }
        else
        {
            current->right = insert(&(current->right),val);
        }
    }
    return *root;
}
void preorder(bst *root)
{
    bst *current = root;
    if(current != NULL)
    {
         printf("%d ",current->data);
         preorder(current->left);
         preorder(current->right);
    }
}
void inorder(bst *root)
{
    bst *current = root;
    if(current != NULL)
    {
        inorder(current->left);
        printf("%d ",current->data);
        inorder(current->right);
    }
}
void postorder(bst *root)
{
    bst *current = root;
    if(current != NULL)
    {
        postorder(current->left);
        postorder(current->right);
        printf("%d ",current->data);
        
    }
}