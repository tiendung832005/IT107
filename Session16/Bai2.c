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
void preOrder(struct Node* root) {
    if (root == NULL) return;
    
    printf("%d ", root->data);
    preOrder(root->left);      
    preOrder(root->right);      
}
void inOrder(struct Node* root) {
    if (root == NULL) return;
    
    inOrder(root->left);        
    printf("%d ", root->data);  
    inOrder(root->right);       
}
void postOrder(struct Node* root) {
    if (root == NULL) return;
    
    postOrder(root->left);   
    postOrder(root->right);     
    printf("%d ", root->data);  
}
int main() {

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

   
    printf("PreOrder: ");
    preOrder(root);
    printf("\n");

    printf("InOrder: ");
    inOrder(root);
    printf("\n");

    printf("PostOrder: ");
    postOrder(root);
    printf("\n");

    return 0;
}

