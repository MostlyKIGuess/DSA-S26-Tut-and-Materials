#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

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

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
	scanf("%d", &arr[i]);
    }

    int *result = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
	result[i] = -1;
    }

    Stack s;
    init(&s);

    for (int i = n - 1; i >= 0; i--) {
	while (!isEmpty(&s) && top(&s) <= arr[i]) {
	    pop(&s);
	}

	if (!isEmpty(&s)) {
	    result[i] = top(&s);
	}

	push(&s, arr[i]);
    }

    for (int i = 0; i < n; i++) {
	printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
