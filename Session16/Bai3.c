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
int countLeaves(struct Node* root) {
    if (root == NULL) {
        return 0; 
    }
    
    if (root->left == NULL && root->right == NULL) {
        return 1; 
    }

 
    return countLeaves(root->left) + countLeaves(root->right);
}
int main() {
    // T?o c�y nh? ph�n m?u
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

   
    int leafCount = countLeaves(root);

    printf("So luong la trong cay nhi phan la: %d\n", leafCount);

    return 0;
}

