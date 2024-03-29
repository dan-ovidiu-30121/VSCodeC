#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node* node) {
    if (node == NULL) {
        return 0;
    } else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        return 1 + max(leftHeight, rightHeight);
    }
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(6);
    root->left->right->right = newNode(7);
    root->left->right->right->right = newNode(8);



    printf("Inaltimea arborelui binar este: %d\n", height(root));

    return 0;
}
