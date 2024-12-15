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

// Ham chen gia tri vao cay nhi phan tim kiem
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

// Ham de quy tim kiem gia tri trong cay
int search(struct Node* root, int value) {
   
    if (root == NULL) {
        return 0;  
    }
    
    if (root->data == value) {
        return 1;  
    }

   
    if (value < root->data) {
        return search(root->left, value);
    }

    
    return search(root->right, value);
}

int main() {
    struct Node* root = NULL;
    int values[] = {20, 10, 30, 5, 15, 25, 35};
    int n = sizeof(values) / sizeof(values[0]);

    // Xay dung cay BST
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    int searchValue;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &searchValue);

    
    if (search(root, searchValue)) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    return 0;
}

