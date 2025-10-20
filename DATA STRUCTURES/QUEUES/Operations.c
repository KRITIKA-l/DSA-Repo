// QUESTION :- WAP to perform enqueue, dequeue and display operations on a queue.

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

struct Queue {
    int data[MAXSIZE];
    int front;
    int rear;
};

void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

void enqueue(struct Queue *q, int value) {
    if (q->rear == MAXSIZE - 1) {
        printf("Queue Overflow!\n");
    } 
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->data[q->rear] = value;
        printf("Inserted: %d\n", value);
    }
}

void dequeue(struct Queue *q) {
    if (q->front == -1) {
        printf("Queue Underflow!\n");
    } 
    else {
        int value = q->data[q->front];
        printf("Deleted: %d\n", value);
        if (q->front == q->rear)
            q->front = q->rear = -1; // Reset when empty
        else
            q->front++;
    }
}

void display(struct Queue q) {
    if (q.front == -1) {
        printf("Queue is Empty!\n");
    } 
    else {
        printf("Queue elements: ");
        for (int i = q.front; i <= q.rear; i++) {
            printf("%d ", q.data[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Queue q;
    initQueue(&q);

    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                display(q);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
