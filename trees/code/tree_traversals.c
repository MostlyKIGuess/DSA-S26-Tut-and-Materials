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

void preorder(Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

#define MAX_SIZE 100

typedef struct {
    Node* data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmptyQueue(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, Node* node) {
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->data[q->rear] = node;
}

Node* dequeue(Queue* q) {
    Node* node = q->data[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return node;
}

void levelOrder(Node* root) {
    if (root == NULL)
        return;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmptyQueue(&q)) {
        Node* curr = dequeue(&q);
        printf("%d ", curr->data);

        if (curr->left != NULL)
            enqueue(&q, curr->left);
        if (curr->right != NULL)
            enqueue(&q, curr->right);
    }
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    printf("Level Order: ");
    levelOrder(root);
    printf("\n");

    return 0;
}
