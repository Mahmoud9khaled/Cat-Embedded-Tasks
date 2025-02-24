#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} DynamicStack;

void initializeDynamicStack(DynamicStack *stack) {
    stack->top = NULL;
}

bool isDynamicStackEmpty(DynamicStack *stack) {
    return stack->top == NULL;
}

void pushDynamicStack(DynamicStack *stack, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int popDynamicStack(DynamicStack *stack) {
    if (isDynamicStackEmpty(stack)) {
        printf("Stack Underflow!\n");
        return -1; // Return an invalid value to indicate underflow
    }
    Node *temp = stack->top;
    int poppedValue = temp->data;
    stack->top = temp->next;
    free(temp);
    return poppedValue;
}

int peekDynamicStack(DynamicStack *stack) {
    if (isDynamicStackEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1; // Return an invalid value to indicate empty stack
    }
    return stack->top->data;
}

void freeDynamicStack(DynamicStack *stack) {
    while (!isDynamicStackEmpty(stack)) {
        popDynamicStack(stack);
    }
}

int main() {
    DynamicStack stack;
    initializeDynamicStack(&stack);

    pushDynamicStack(&stack, 10);
    pushDynamicStack(&stack, 20);
    pushDynamicStack(&stack, 30);

    printf("Top element: %d\n", peekDynamicStack(&stack));

    printf("Popped element: %d\n", popDynamicStack(&stack));
    printf("Popped element: %d\n", popDynamicStack(&stack));

    printf("Top element: %d\n", peekDynamicStack(&stack));

    freeDynamicStack(&stack);

    return 0;
}