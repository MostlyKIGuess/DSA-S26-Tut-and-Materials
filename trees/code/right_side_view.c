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

void rightSideViewHelper(Node *root, int level, int *maxLevel) {
    if (root == NULL)
	return;

    if (level > *maxLevel) {
	printf("%d ", root->data);
	*maxLevel = level;
    }

    rightSideViewHelper(root->right, level + 1, maxLevel);
    rightSideViewHelper(root->left, level + 1, maxLevel);
}

void rightSideView(Node *root) {
    int maxLevel = -1;
    rightSideViewHelper(root, 0, &maxLevel);
}

int main() {
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Right Side View: ");
    rightSideView(root);
    printf("\n");

    Node *root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);
    root2->left->right = createNode(5);
    root2->left->left = createNode(6);
    root2->left->left->left = createNode(8);

    printf("Right Side View: ");
    rightSideView(root2);
    printf("\n");

    return 0;
}
