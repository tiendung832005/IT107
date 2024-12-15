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

// Ham chen vao cay nhi phan
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

// Ham duyet cay theo tien thu tu
void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);  
        preOrder(root->left);      
        preOrder(root->right);     
    }
}

// Ham duyet cay theo trung thu tu
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);       
        printf("%d ", root->data);  
        inOrder(root->right);       
    }
}

// Ham duyet cay theo hau thu tu
void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);      
        postOrder(root->right);    
        printf("%d ", root->data); 
    }
}

int main() {
    struct Node* root = NULL;
    int values[] = {4, 2, 5, 1, 3};
    int n = sizeof(values) / sizeof(values[0]);

    // Chen cac gia tri vao cay
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    // Duyet cay theo cac thu tu khac nhau
    printf("Duyet Tien Thu Tu: \n");
    preOrder(root);
    printf("\n");

    printf("Duyet Trung Thu Tu: \n");
    inOrder(root);
    printf("\n");

    printf("Duyet Hau Thu Tu: \n");
    postOrder(root);
    printf("\n");

    return 0;
}

