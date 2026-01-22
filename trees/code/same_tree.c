#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int isSameTree(Node* p, Node* q) {
    if (p == NULL && q == NULL)
        return 1;
    if (p == NULL || q == NULL)
        return 0;

    return (p->data == q->data) &&
           isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}

int main() {
    Node* p = createNode(1);
    p->left = createNode(2);
    p->right = createNode(3);

    Node* q = createNode(1);
    q->left = createNode(2);
    q->right = createNode(3);

    printf("p and q same: %s\n", isSameTree(p, q) ? "Yes" : "No");

    Node* r = createNode(1);
    r->left = createNode(2);
    r->right = createNode(4);

    printf("p and r same: %s\n", isSameTree(p, r) ? "Yes" : "No");

    return 0;
}
