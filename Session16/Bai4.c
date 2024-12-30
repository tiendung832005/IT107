#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
int search(struct Node* root, int value) {
    if (root == NULL) {
        return 0; 
    }
    
    if (root->data == value) {
        return 1; 
    }

    
    return search(root->left, value) || search(root->right, value);
}
int main() {
    
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

   
    int valueToSearch;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &valueToSearch);


    if (search(root, valueToSearch)) {
        printf("Tim thay gia tri %d trong cay nhi phan.\n", valueToSearch);
    } else {
        printf("Khong tim thay giá tri %d trong cay nhi phan.\n", valueToSearch);
    }

    return 0;
}

