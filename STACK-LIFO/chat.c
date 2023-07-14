#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int data[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initialize(Stack *stack)
{
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack)
{
    return (stack->top == -1);
}

// Function to check if the stack is full
int isFull(Stack *stack)
{
    return (stack->top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(Stack *stack, int element)
{
    if (isFull(stack))
    {
        printf("Stack Overflow: Cannot push element onto the stack.\n");
        return;
    }
    stack->data[++stack->top] = element;
}

// Function to pop an element from the stack
int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow: Cannot pop element from the stack.\n");
        return -1;
    }
    return stack->data[stack->top--];
}

// Function to get the top element of the stack
int top(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->data[stack->top];
}

int main()
{
    Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", top(&stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    printf("Top element: %d\n", top(&stack));

    return 0;
}
