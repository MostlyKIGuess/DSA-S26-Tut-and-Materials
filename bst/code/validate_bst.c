#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int isValid(Node* root, long min, long max) {
    if (root == NULL) return 1;
    if (root->data <= min || root->data >= max) return 0;
    return isValid(root->left, min, root->data) &&
           isValid(root->right, root->data, max);
}

int isValidBST(Node* root) {
    return isValid(root, LONG_MIN, LONG_MAX);
}

int main() {
    Node* root = createNode(8);
    root->left = createNode(3);
    root->right = createNode(10);
    root->left->left = createNode(1);
    root->left->right = createNode(6);
    root->left->right->left = createNode(4);
    root->left->right->right = createNode(7);
    root->right->right = createNode(14);
    root->right->right->left = createNode(13);

    if (isValidBST(root))
        printf("Valid BST\n");
    else
        printf("Not a valid BST\n");

    return 0;
}
