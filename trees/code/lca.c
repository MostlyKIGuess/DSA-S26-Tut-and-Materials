#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

Node* LCA(Node* root, Node* p, Node* q) {
    if (root == NULL || root == p || root == q)
        return root;

    Node* left = LCA(root->left, p, q);
    Node* right = LCA(root->right, p, q);

    if (left && right)
        return root;

    return left ? left : right;
}

Node* findNode(Node* root, int value) {
    if (root == NULL || root->data == value)
        return root;
    Node* left = findNode(root->left, value);
    if (left)
        return left;
    return findNode(root->right, value);
}

int main() {
    Node* root = createNode(3);
    root->left = createNode(5);
    root->right = createNode(1);
    root->left->left = createNode(6);
    root->left->right = createNode(2);
    root->right->left = createNode(0);
    root->right->right = createNode(8);
    root->left->right->left = createNode(7);
    root->left->right->right = createNode(4);

    Node* p = findNode(root, 5);
    Node* q = findNode(root, 1);

    Node* lca = LCA(root, p, q);
    printf("LCA of 5 and 1: %d\n", lca->data);

    p = findNode(root, 6);
    q = findNode(root, 4);
    lca = LCA(root, p, q);
    printf("LCA of 6 and 4: %d\n", lca->data);

    return 0;
}
