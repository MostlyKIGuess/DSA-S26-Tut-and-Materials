#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode *front, *rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

void enqueue(Queue* q, Node* treeNode) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->treeNode = treeNode;
    temp->next = NULL;

    if (q->rear == NULL)
        q->front = q->rear = temp;
    else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

Node* dequeue(Queue* q) {
    if (q->front == NULL)
        return NULL;

    QueueNode* temp = q->front;
    Node* treeNode = temp->treeNode;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return treeNode;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void levelOrder(Node* root) {
    if (root == NULL)
        return;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        int levelSize = 0;
        QueueNode* temp = q.front;
        while (temp != NULL) {
            levelSize++;
            temp = temp->next;
        }

        for (int i = 0; i < levelSize; i++) {
            Node* curr = dequeue(&q);
            printf("%d ", curr->data);

            if (curr->left != NULL)
                enqueue(&q, curr->left);
            if (curr->right != NULL)
                enqueue(&q, curr->right);
        }
        printf("\n");
    }
}

int main() {
    Node* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    printf("Level Order Traversal:\n");
    levelOrder(root);

    return 0;
}
