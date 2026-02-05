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

Node* searchBST(Node* root, int val) {
    if (root == NULL) return NULL;
    if (root->data == val) return root;

    if (val < root->data)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
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

    int val = 6;
    Node* result = searchBST(root, val);

    if (result)
        printf("Found %d in BST\n", result->data);
    else
        printf("%d not found in BST\n", val);

    return 0;
}
