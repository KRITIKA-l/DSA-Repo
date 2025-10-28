// Implement insertion, deletion and display in Circular Queue.

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 4

int data[MAXSIZE];

int front = -1, rear = -1;

int isfull()
{
    return (rear + 1) % MAXSIZE == front;
}

int isempty()
{
    return (front == -1);
}

void enqueue(int value) 
{
    if (isfull()) 
    {
        printf("Queue Overflow!\n");
    } 
    else 
    {
        if (isempty())
        {    
            front = rear=0;
        }
        else
        {    
            rear = (rear +1)%MAXSIZE;
        }

        data[rear] = value;
        printf("Inserted: %d\n", value);
    }
}

void dequeue() 
{
    if (isempty()) 
    {
        printf("Queue Underflow!\n");
    } 
    else 
    {
        int value = data[front];
        printf("Deleted: %d\n", value);

        if (front == rear)
            front = rear = -1; 
        else
            front = (front+1) % MAXSIZE;
    }
}

void display() 
{
    if (isempty()) 
    {
        printf("Queue is Empty!\n");
    } 
    else 
    {
        printf("Queue elements: ");
        int i = front;
        while (1) 
        {
            printf("%d ", data[i]);
            if (i == rear)
                break;
            i = (i + 1) % MAXSIZE;
        }
        printf("\n");
    }
}

int main() 
{


    int choice, value;

    while (choice != 4) 
    {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue( value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}