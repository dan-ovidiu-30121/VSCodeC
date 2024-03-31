#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int val;
    struct List *next;
} Node;
Node *mergeTwoLists(Node *l1, Node *l2)
{
    Node *newHead = NULL;
    Node *result = (Node *)malloc(sizeof(Node));
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    if (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            result = l1;
            l1 = result->next;
        }
        else
        {
            result = l2;
            l2 = result->next;
        }
    }
    newHead = result;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            result->next = l1;
            result = l1;
            l1 = result->next;
        }
        else
        {
            result->next = l2;
            result = l2;
            l2 = result->next;
        }
    }
    if (l1 == NULL)
        result->next = l2;
    if (l2 == NULL)
        result->next = l1;
    return newHead;
}
Node *createLinkedList(int n)
{
    int i = 0;
    Node *head = NULL;
    Node *temp = NULL;
    Node *p = NULL;

    for (i = 0; i < n; i++)
    {
        temp = (Node *)malloc(sizeof(Node));
        printf("\nValue %d: ",i+1);
        scanf("%d", &(temp->val));
        temp->next = NULL;

        if(head == NULL)
        {
            head = temp;
        }
        else
        {
            p = head;
            while(p->next != NULL)
              p = p->next;
            p->next = temp;
        }
    }
    return head;
}
void displayList(Node *head)
{
    Node *p = head;
    while(p != NULL)
    {
        printf("%d ",p->val);
        p = p->next;
    }
}
int main()
{
    int n1 = 0, n2 = 0;

    Node *head1 = NULL;
    printf("Number of nodes for first list: ");
    scanf("%d",&n1);
    head1 = createLinkedList(n1);

    printf("Number of nodes for second list: ");
    scanf("%d",&n2);
    Node *head2 = NULL;
    head2 = createLinkedList(n2);

    Node* result = mergeTwoLists(head1,head2);
    displayList(result);
    return 0;
}