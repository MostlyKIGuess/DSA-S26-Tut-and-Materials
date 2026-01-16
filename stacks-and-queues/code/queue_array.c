#include <limits.h>
#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} Queue;

void init(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) { return q->front == -1; }

int isFull(Queue *q) { return q->rear == MAX_SIZE - 1; }

void push(Queue *q, int value) {
    if (isFull(q)) {
	printf("Queue Full\n");
	return;
    }
    if (q->front == -1)
	q->front = 0;
    q->rear = q->rear + 1;
    q->data[q->rear] = value;
}

int pop(Queue *q) {
    if (isEmpty(q)) {
	printf("Queue Underflow\n");
	return INT_MIN;
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
	q->front = q->rear = -1;
    } else {
	q->front = q->front + 1;
    }
    return value;
}

int front(Queue *q) {
    if (isEmpty(q)) {
	printf("Queue is empty\n");
	return INT_MIN;
    }
    return q->data[q->front];
}

int main() {
    Queue q;
    init(&q);

    push(&q, 10);
    push(&q, 20);
    push(&q, 30);

    printf("Front element: %d\n", front(&q));
    printf("Popped: %d\n", pop(&q));
    printf("Popped: %d\n", pop(&q));
    printf("Front element: %d\n", front(&q));

    return 0;
}
