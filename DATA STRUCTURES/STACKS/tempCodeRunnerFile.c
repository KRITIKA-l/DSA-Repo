// QUESTION :- WAP To convert infix expression to postfix expression using stacks.

#include<stdio.h>
#include<string.h>

#define Max_Size 20

typedef struct
{
    char arr[Max_Size];
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

void push(stack *stack, char value)
{
    if(isfull(stack))
    {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    stack ->top=stack->top+1;
    stack->arr[stack->top]=value;
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


int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void infixToPostfix(char s[], char postfix[])
{
    stack s1;
    initialize(&s1);

    int k = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        char c = s[i];
        if (c == ' ')
            continue;
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            postfix[k++] = c;
        }
        else if (c == '(')
        {
            push(&s1, '(');
        }
        else if (c == ')')
        {
            while (!isempty(&s1) && peek(&s1) != '(')
            {
                postfix[k++] = pop(&s1);
            }
            if (!isempty(&s1) && peek(&s1) == '(') 
            {
                pop(&s1); 
            }
        }
        else
        {
            while (!isempty(&s1) && precedence(c) <= precedence(peek(&s1))) 
            {
                postfix[k++] = pop(&s1);
            }
            push(&s1, c);
        }
    }
    while (!isempty(&s1)) 
    {
        postfix[k++] = pop(&s1);
    }

    postfix[k] = '\0';
}


int main()
{
    char infix[100];
    char postfix[100];

    printf("Enter an infix expression: ");
    gets(infix);

    infixToPostfix(infix, postfix);

    printf("Postfix: %s\n", postfix);

    return 0;

}