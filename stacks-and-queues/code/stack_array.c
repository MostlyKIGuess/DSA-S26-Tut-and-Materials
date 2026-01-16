#include <limits.h>
#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void init(Stack *s) { s->top = -1; }

int isEmpty(Stack *s) { return s->top == -1; }

int isFull(Stack *s) { return s->top == MAX_SIZE - 1; }

void push(Stack *s, int value) {
    if (isFull(s)) {
	printf("Stack Overflow\n");
	return;
    }
    s->top = s->top + 1;
    s->data[s->top] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
	printf("Stack Underflow\n");
	return INT_MIN;
    }
    int value = s->data[s->top];
    s->top = s->top - 1;
    return value;
}

int top(Stack *s) {
    if (isEmpty(s)) {
	printf("Stack is empty\n");
	return INT_MIN;
    }
    return s->data[s->top];
}

int main() {
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top: %d\n", top(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Top: %d\n", top(&s));

    return 0;
}
