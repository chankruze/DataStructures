// Doubly List
/*
 * @Author: chankruze (Chandan Kumar Mandal) 
 * @Date: 2019-06-20 22:44:01 
 * @Last Modified by: chankruze (Chandan Kumar Mandal)
 * @Last Modified time: 2019-06-20 23:26:29
 */
#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

struct Node *GetNewNode(int x)
{
    struct Node *newNode = (Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertAtHead(Node **head, int x)
{
    struct Node *newNode = GetNewNode(x);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    (*head)->prev = newNode;
    newNode->next = *head;
    *head = newNode;
}

void Print(Node *head)
{
    struct Node *temp = head;
    printf("Forward: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ReversePrint(Node *head)
{
    struct Node *temp = head;
    if (temp == NULL)
        return;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("Reverse: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    Node *head = NULL;
    InsertAtHead(&head, 2);
    Print(head);
    ReversePrint(head);

    InsertAtHead(&head, 5);
    Print(head);
    ReversePrint(head);

    InsertAtHead(&head, 8);
    Print(head);
    ReversePrint(head);

    InsertAtHead(&head, 10);
    Print(head);
    ReversePrint(head);
}