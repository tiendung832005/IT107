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

// Ham them mot node vao vi tri chi dinh
void insertAtPosition(Node** head, int data, int position) {
    // Ki?m tra n?u v? trí yêu c?u h?p l?
    Node* newNode = createNode(data);
    Node* temp = *head;
    int count = 0;

    
    if (position == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    // Duyet danh sach den vi tri can chen
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

   
    if (temp == NULL) {
        printf("Error: Invalid position.\n");
        free(newNode);
        return;
    }

    
    newNode->next = temp->next;
    newNode->prev = temp;

    
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

// Ham in danh sach lien ket doi
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Them mot so node vao danh sach
    insertAtPosition(&head, 10, 0);  
    insertAtPosition(&head, 20, 1);  
    insertAtPosition(&head, 30, 2);  
    insertAtPosition(&head, 40, 1);  

    // In danh sach lien ket doi
    printList(head);

   
    insertAtPosition(&head, 50, 10);

    return 0;
}

