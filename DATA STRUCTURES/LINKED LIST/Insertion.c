// QUESTION :- Write a C program to create a singly linked list by inserting N elements and display the elements of the linked list. 

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL ;
    struct node *temp = NULL;
    struct node *newnode = NULL;

    int n, i, value;

    printf("Enter number of elements : ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter element %d : ", i);
        scanf("%d", &value);

        newnode -> data = value;
        newnode -> next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = head;
        }
        else
        {
            temp -> next = newnode;
            temp = newnode;
        }
    }

    temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp -> data);
        temp = temp -> next; 
    }
    printf("NULL.\n");
    return 0;
}
