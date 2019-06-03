// Linked List: Insert a node at nth position

/*
 * @Author: chankruze (Chandan Kumar Mandal) 
 * @Date: 2019-06-03 18:01:55 
 * @Last Modified by: chankruze (Chandan Kumar Mandal)
 * @Last Modified time: 2019-06-04 02:16:21
 */

#include <stdlib.h>
#include <stdio.h>

//Define identifier Node
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
    //Create new node and store it's address to new_node
    Node *new_node = (Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    //Add first node (case 1: list is empty)
    if (n == 1)
    {
        new_node->next = *head;
        *head = new_node;
        return;
    }
    //Save head's link in a temp var (address of first node)
    Node *temp = *head;
    //Iterate through existing nodes (case 2: list is not empty)
    for (int i = 0; i < n - 2; i++)
    {
        //Set temp to (n-1)th/previous node where new node inserts
        temp = temp->next;
    }
    //Links to next node
    new_node->next = temp->next;
    //Break previous & next node link and set link to new node in previous node
    temp->next = new_node;
}

/**
 * Function to print the list
 */
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

/**
 * Function t0 delete a node at position n
 */
void Delete(Node **head, int n)
{
    Node *temp1 = *head;
    if (n == 1)
    {
        *head = temp1->next; // head now points to 2nd node
        free(temp1);
        return;
    }
    int i;
    for (i = 0; i < n - 2; i++)
    {
        // temp1 points to (n-1)th node
        temp1 = temp1->next;
    }
    Node *temp2 = temp1->next; // set temp2 to nth Node address
    temp1->next = temp2->next; // links previos to (n+1)tn node
    free(temp2);
}

int main()
{
    Node *head = NULL; //EMPTY LIST

    //Insert 2 at 1st position
    Insert(&head, 2, 1);
    Print(head); //List is : 2

    //Insert 3 at 2st position
    Insert(&head, 3, 2);
    Print(head); //List is : 2 3

    //Insert 4 at 1st position (rest after 1st will be pushed to next)
    Insert(&head, 4, 1);
    Print(head); //List is : 4 2 3

    //Insert 5 at 2st position (rest after 2nd will be pushed to next)
    Insert(&head, 5, 2);
    Print(head); //List is : 4 5 2 3

    //Insert 8 at 3st position
    Insert(&head, 8, 3);
    Print(head); //List is : 4 5 8 2 3

    //Insert 10 at 3st position (rest after 3rd will be pushed to next)
    Insert(&head, 10, 3);
    Print(head); //List is : 4 5 10 8 2 3

    int n;
    printf("Enter the position of the node to delete :\n");
    scanf("%d", &n);
    Delete(&head, n);
    Print(head);

    printf("\nYeh ! I learned inserting node at the nth position of a linked list ...\n");
}