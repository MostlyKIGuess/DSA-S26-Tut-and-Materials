#include <limits.h>
#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void init(Stack *s) { s->top = -1; }

int isEmpty(Stack *s) { return s->top == -1; }

void push(Stack *s, int value) {
    s->top = s->top + 1;
    s->data[s->top] = value;
}

int pop(Stack *s) {
    int value = s->data[s->top];
    s->top = s->top - 1;
    return value;
}

int top(Stack *s) { return s->data[s->top]; }

typedef struct {
    Stack input;
    Stack output;
} Queue;

void queueInit(Queue *q) {
    init(&(q->input));
    init(&(q->output));
}

void q_push(Queue *q, int value) { push(&(q->input), value); }

int q_pop(Queue *q) {
    if (isEmpty(&(q->output))) {
	while (!isEmpty(&(q->input))) {
	    push(&(q->output), pop(&(q->input)));
	}
    }

    if (isEmpty(&(q->output))) {
	printf("Queue is empty\n");
	return INT_MIN;
    }

    return pop(&(q->output));
}

int main() {
    Queue q;
    queueInit(&q);

    q_push(&q, 1);
    q_push(&q, 2);
    printf("Dequeued: %d\n", q_pop(&q));
    q_push(&q, 3);
    printf("Dequeued: %d\n", q_pop(&q));
    printf("Dequeued: %d\n", q_pop(&q));

    return 0;
}
