#include <stdio.h>
#include <stdlib.h>

// Dinh nghia cau truc cua mot phan tu trong danh sach lien ket doi
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Ham tao mot node moi
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Ham in ra cac gia tri cua danh sach lien ket doi theo thu tu nguoc lai
void printListReverse(Node* head) {
    Node* temp = head;
    
    // Duyet den phan tu cuoi cung
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }

    // Duyet tu cuoi ve dau
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    // Tao danh sach lien ket doi
    Node* head = createNode(1);
    Node* second = createNode(2);
    Node* third = createNode(3);
    Node* fourth = createNode(4);
    
    // Lien ket cac node lai voi nhau
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    
    // In ra cac phan tu theo thu tu nguoc lai
    printListReverse(head);
    
    return 0;
}

