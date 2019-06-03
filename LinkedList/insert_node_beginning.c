// Linked List: Insert a node at beginning
/*
 * @Author: chankruze (Chandan Kumar Mandal) 
 * @Date: 2019-06-02 21:40:46 
 * @Last Modified by: chankruze (Chandan Kumar Mandal)
 * @Last Modified time: 2019-06-04 00:32:02
 */
#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void Insert(Node **head, int x)
{
    Node *new_node = (Node *)malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->next = *head;
    *head = new_node;
}

void Print(Node *head)
{
    printf("List is : ");
    while (head != NULL)
    {
        printf(" %d", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    Node *head = NULL; //EMPTY LIST
    printf("How many numbers to add ?\n");
    int n, i, x;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the number\n");
        scanf("%d", &x);
        Insert(&head, x);
        Print(head);
    }
    printf("\nYeh ! I learned inserting node at the beginning of a linked list ...\n");
}