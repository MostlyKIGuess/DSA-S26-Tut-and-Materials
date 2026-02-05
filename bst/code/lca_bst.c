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

Node* LCA(Node* root, int p, int q) {
    if (root == NULL) return NULL;

    if (p < root->data && q < root->data)
        return LCA(root->left, p, q);

    if (p > root->data && q > root->data)
        return LCA(root->right, p, q);

    return root;
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

    Node* lca = LCA(root, 1, 7);
    if (lca)
        printf("LCA of 1 and 7: %d\n", lca->data);

    lca = LCA(root, 4, 13);
    if (lca)
        printf("LCA of 4 and 13: %d\n", lca->data);

    return 0;
}
