#include <limits.h>
#include <stdio.h>

#define MAX_SIZE 5

typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} CircularQueue;

void init(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(CircularQueue *q) { return q->front == -1; }

int isFull(CircularQueue *q) { return (q->rear + 1) % MAX_SIZE == q->front; }

void push(CircularQueue *q, int value) {
    if (isFull(q)) {
	printf("Queue Overflow\n");
	return;
    }
    if (q->front == -1)
	q->front = 0;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = value;
}

int pop(CircularQueue *q) {
    if (isEmpty(q)) {
	printf("Queue Underflow\n");
	return INT_MIN;
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
	q->front = q->rear = -1;
    } else {
	q->front = (q->front + 1) % MAX_SIZE;
    }
    return value;
}

int main() {
    CircularQueue q;
    init(&q);

    push(&q, 10);
    push(&q, 20);
    push(&q, 30);
    pop(&q); // poppin 10
    push(&q, 40);
    push(&q, 50);
    push(&q, 60);

    printf("Elements: ");
    while (!isEmpty(&q)) {
	printf("%d ", pop(&q));
    }
    printf("\n");

    return 0;
}
