#include <stdio.h>

#define MAX_SIZE 1000

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void init(Stack *s) { s->top = -1; }

int isEmpty(Stack *s) { return s->top == -1; }

void push(Stack *s, char c) {
    s->top = s->top + 1;
    s->data[s->top] = c;
}

char pop(Stack *s) {
    char value = s->data[s->top];
    s->top = s->top - 1;
    return value;
}

char peek(Stack *s) { return s->data[s->top]; }

int isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
	   (opening == '{' && closing == '}') ||
	   (opening == '[' && closing == ']');
}

int isValid(char *s) {
    Stack stack;
    init(&stack);

    for (int i = 0; s[i] != '\0'; i++) {
	if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
	    push(&stack, s[i]);
	} else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
	    if (isEmpty(&stack) || !isMatchingPair(peek(&stack), s[i])) {
		return 0;
	    }
	    pop(&stack);
	}
    }

    return isEmpty(&stack);
}

int main() {
    char s[MAX_SIZE];
    scanf("%s", s);

    if (isValid(s)) {
	printf("Valid\n");
    } else {
	printf("Invalid\n");
    }

    return 0;
}
