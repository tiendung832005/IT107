#include <stdio.h>
#include <stdlib.h>

// Cau truc Node bieu dien mot nut trong cay nhi phan
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

// Ham chen gia tri vao cay nhi phan tim kiem
void insert(Node **root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
    } else if (value < (*root)->data) {
        insert(&(*root)->left, value);
    } else {
        insert(&(*root)->right, value);
    }
}

// Duyet cay theo thu tu truoc (pre-order)
void preOrder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

//Duyet cay theo thu tu giua (in-order)
void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Duyet cay theo thu tu sau (post-order)
void postOrder(Node *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    Node *root = NULL;
    int n;

    printf("Nhap so luong nut: ");
    scanf("%d", &n);

    printf("Nhap cac gia tri: \n");
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insert(&root, value);
    }

    printf("Duyet Pre-Order: ");
    preOrder(root);
    printf("\n");

    printf("Duyet In-Order: ");
    inOrder(root);
    printf("\n");

    printf("Duyet Post-Order: ");
    postOrder(root);
    printf("\n");

    return 0;
}

