#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int max(int a, int b) {
    if (a > b) {
	return a;
    }
    return b;
}

int maxDepth(Node *root) {
    if (root == NULL)
	return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Maximum Depth: %d\n", maxDepth(root));

    Node *single = createNode(1);
    printf("Single node depth: %d\n", maxDepth(single));

    printf("Empty tree depth: %d\n", maxDepth(NULL));

    return 0;
}
