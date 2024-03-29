#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}Node;
void insertEnd(Node **head, int val);
void printList(Node* head);
void insertBeg(Node **head, int val);
void deleteElement(Node **head, int val);
int main()
{
    Node *head = NULL;
    insertEnd(&head,1);
    insertEnd(&head,2);
    insertBeg(&head,3);
    deleteElement(&head,1);
    printList(head);
    return 0;
}
void insertEnd(Node **head, int val)
{
    Node *tmp =(Node *)malloc(sizeof(Node));
    tmp->data = val;
    tmp->next = NULL;
    if(*head == NULL)
    {
        *head = tmp;
    }
    else
    {
        Node *last = *head;
        while(last->next != NULL)
        {
            last = last->next;
        }
        last->next = tmp;
    }
}
void insertBeg(Node **head, int val){
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->data = val;
    tmp->next = *head;
    *head = tmp;
}
void deleteElement(Node **head, int val) {
    Node *current = *head; 
    Node *prev = NULL;

    while (current != NULL) {
        if (current->data == val) {
            if (current == *head) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }
}
void printList(Node* head)
{
    Node *current = head;
    while(current != NULL)
    {
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}