#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} StaticStack;

void initializeStaticStack(StaticStack *stack) {
    stack->top = -1;
}

bool isStaticStackEmpty(StaticStack *stack) {
    return stack->top == -1;
}

bool isStaticStackFull(StaticStack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void pushStaticStack(StaticStack *stack, int value) {
    if (isStaticStackFull(stack)) {
        printf("Stack Overflow!\n");
        return;
    }
    stack->data[++stack->top] = value;
}

int popStaticStack(StaticStack *stack) {
    if (isStaticStackEmpty(stack)) {
        printf("Stack Underflow!\n");
        return -1; // Return an invalid value to indicate underflow
    }
    return stack->data[stack->top--];
}

int peekStaticStack(StaticStack *stack) {
    if (isStaticStackEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1; // Return an invalid value to indicate empty stack
    }
    return stack->data[stack->top];
}

int main() {
    StaticStack stack;
    initializeStaticStack(&stack);

    pushStaticStack(&stack, 10);
    pushStaticStack(&stack, 20);
    pushStaticStack(&stack, 30);

    printf("Top element: %d\n", peekStaticStack(&stack));

    printf("Popped element: %d\n", popStaticStack(&stack));
    printf("Popped element: %d\n", popStaticStack(&stack));

    printf("Top element: %d\n", peekStaticStack(&stack));

    return 0;
}