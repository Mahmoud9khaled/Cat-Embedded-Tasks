#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Define the Queue structure
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
bool isFull(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

// Function to check if the queue is empty
bool isEmpty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

// Function to add an element to the queue (enqueue)
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full, cannot enqueue element.\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Enqueued %d to the queue.\n", value);
    }
}

// Function to remove an element from the queue (dequeue)
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty, cannot dequeue element.\n");
        return -1;
    } else {
        int item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            // Reset the queue after the last element is dequeued
            initializeQueue(q);
        }
        printf("Dequeued %d from the queue.\n", item);
        return item;
    }
}

// Function to peek at the front element of the queue
int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty, no element to peek.\n");
        return -1;
    } else {
        return q->items[q->front];
    }
}

// Function to display the queue
void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    initializeQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    displayQueue(&q);

    printf("Front element is: %d\n", peek(&q));

    dequeue(&q);
    displayQueue(&q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q); // This will trigger the "Queue is empty" message

    return 0;
}