#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* head = NULL;

void insertAtBeginning(int data)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insertatend(int data)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
        return;
    }
    struct node *temp = head;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = new_node;
}

void insertatpositionbefore(int data, int position)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (position == 1)
    {
        new_node->next = head;
        head = new_node;
        return;
    }

    int count = 1;
    struct node *temp = head;

    while (temp != NULL && count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        printf("Position is beyond the length of the list. Inserting at the end.\n");
        insertatend(data);
        free(new_node);  
        return;
    }

    new_node->next = temp -> next;
    temp->next = new_node;
}


void insertatpositionafter(int data, int position)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL)
    {
        if (position == 0)  
        {
            head = new_node;
            return;
        }
        else
        {
            printf("List is empty. Cannot insert after position %d.\n", position);
            free(new_node);
            return;
        }
    }

    struct node *temp = head;
    int count = 1;

    while (temp != NULL && count < position)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        printf("Position %d is beyond the length of the list. Inserting at the end.\n", position);
        insertatend(data);
        free(new_node);
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}


void printList()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() 
{
    int choice, data, position;

    while (1) {
        printf("\n------ Linked List Menu ------\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert Before Position\n");
        printf("4. Insert After Position\n");
        printf("5. Display List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;

            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertatend(data);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position to insert before: ");
                scanf("%d", &position);
                insertatpositionbefore(data, position);
                break;

            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position to insert after: ");
                scanf("%d", &position);
                insertatpositionafter(data, position);
                break;

            case 5:
                printList();
                break;

            case 0:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}