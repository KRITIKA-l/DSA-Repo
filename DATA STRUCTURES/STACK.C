#include<stdio.h>
#include<stdbool.h>

#define Max_Size 20

typedef struct{
    int arr[Max_Size];
    int top;
} stack;

void initialize(stack *stack)
{
    stack -> top = -1;
}

int isfull(stack *stack)
{
    return(stack -> top == Max_Size-1);
}

int isempty(stack *stack)
{
    return (stack -> top == -1);
}

void push(stack *stack, int value)
{
    if(isfull(stack))
    {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    stack ->top=stack->top+1;
    stack->arr[stack->top]=value;
    printf("Pushed %d onto the stack.\n", value);
}

int pop(stack *stack)
{
    if(isempty(stack))
    {
        printf("Stack underflow! Cannot pop.\n");
        return -1;
    }
    int topelement = stack -> arr[stack->top];
    stack -> top = stack -> top -1;
    return topelement;
}

int peek(stack *stack)
{
    if (isempty(stack)) 
    {
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    }
    return stack->arr[stack->top];
}

void display(stack *stack) 
{
    if (isempty(stack)) 
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements (top to bottom):\n");
    for (int i = stack->top; i >= 0; i--) 
    {
        printf("%d\n", stack->arr[i]);
    }
}

int main()
{
    stack s;
    initialize(&s);

    int choice = 0, value, result;

    while (choice != 5) 
    {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                result = pop(&s);
                if (result != -1)
                    printf("Popped element: %d\n", result);
                break;
            case 3:
                result = peek(&s);
                if (result != -1)
                    printf("Top element (peek): %d\n", result);
                break;
            case 4:
                display(&s);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

}
