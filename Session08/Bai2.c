#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Ham them nut vao cay theo quy tac cay nhi phan tim kiem
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Ham tim cac dinh thuoc lop 2
void findLevel2Nodes(struct Node* root) {
    if (root != NULL) {
        if (root->left != NULL) {
            if (root->left->left != NULL || root->left->right != NULL) {
                printf("%d ", root->left->data);
            }
        }
        if (root->right != NULL) {
            if (root->right->left != NULL || root->right->right != NULL) {
                printf("%d ", root->right->data);
            }
        }
    }
}

int main() {
    struct Node* root = NULL;

    // Xay dung cay theo du lieu da cho
    root = createNode(1); 

    // Them cac nut con cho nut 1
    root->left = createNode(2);  
    root->right = createNode(3); 

    // Them cac nut con cho nut 2
    root->left->left = createNode(4);  
    root->left->right = createNode(5); 

    // Them nut con cho nut 3
    root->right->left = createNode(6); 

    // In ra cac dinh thuoc lop 2
    printf("Cac dinh lop 2: ");
    findLevel2Nodes(root);
    printf("\n");

    return 0;
}

