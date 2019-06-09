// Linked List: Insert a node at nth position

/*
 * @Author: chankruze (Chandan Kumar Mandal) 
 * @Date: 2019-06-03 18:01:55 
 * @Last Modified by: chankruze (Chandan Kumar Mandal)
 * @Last Modified time: 2019-06-10 01:33:54
 */

#include <stdlib.h>
#include <stdio.h>

// define identifier Node
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

/**
 * Function to insert nodes at nth position
 */
void Insert(Node **head, int data, int n)
{
    // Create new node and store it's address to new_node
    Node *new_node = (Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    // Add first node (case 1: list is empty)
    if (n == 1)
    {
        new_node->next = *head;
        *head = new_node;
        return;
    }
    // save head's link in a temp var (address of first node)
    Node *temp = *head;
    // Iterate through existing nodes (case 2: list is not empty)
    for (int i = 0; i < n - 2; i++)
    {
        // set temp to (n-1)th/previous node where new node inserts
        temp = temp->next;
    }
    // links to next node
    new_node->next = temp->next;
    // break previous & next node link and set link to new node in previous node
    temp->next = new_node;
}

/**
 * Function to print the list
 */
void Print(Node *head)
{
    while (head != NULL)
    {
        printf(" %d", head->data);
        head = head->next;
    }
    printf("\n");
}

/**
 * Function to print the list using recursion
 */
void ReversePrint(Node *head)
{

    if (head == NULL)
    {
        printf("\n");
        return;
    }
    ReversePrint(head->next);
    printf(" %d", head->data);
}

int main()
{
    Node *head = NULL; //EMPTY LIST

    Insert(&head, 2, 1);
    Insert(&head, 3, 2);
    Insert(&head, 4, 1);
    Insert(&head, 5, 2);
    Insert(&head, 8, 3);
    Insert(&head, 10, 3);

    // Print Linked List
    printf("-- Original List --\n");
    Print(head);
    printf("\n");
    // Print Linked List In Reverse Order
    printf("-- List In Reverse Order --\n");
    ReversePrint(head);

    printf("\nYeh ! I learned reversing a linked list ...\n");
}