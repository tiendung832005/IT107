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

// Ham chen gia tri vao cay (cay nhi phan binh thuong)
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    // Gia tri be hon se chen vao ben trai, gia tri lon hon se chen vao ben phai
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Ham tinh chieu cao cua cay
int height(struct Node* root) {
    if (root == NULL) {
        return 0;  
    }

    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    struct Node* root = NULL;

    // Xay dung cay
    root = createNode(1); 

    // Them cac nut con cho nut 1
    root->left = createNode(2);
    root->right = createNode(3);

    // Them cac nut con cho nut 2
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Them nut con cho nut 3
    root->right->left = createNode(6); 

    
    int treeHeight = height(root);

    
    printf("Chieu cao cua cay: %d\n", treeHeight);

    return 0;
}

