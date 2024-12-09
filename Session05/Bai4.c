#include <stdio.h>
#include <stdlib.h>

// Dinh nghia cau truc cho mot phan tu trong danh sach lien ket doi
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Ham tao mot nut moi
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Ham dem so luong phan tu trong danh sach lien ket doi
int countElements(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    return count;
}

// Ham in danh sach lien ket doi
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf(" <-> NULL\n");
}

int main() {
    // Tao mot danh sach lien ket doi voi cac phan tu
    struct Node* head = createNode(2);
    head->next = createNode(4);
    head->next->prev = head;
    head->next->next = createNode(6);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(8);
    head->next->next->next->prev = head->next->next;

    // In danh sach
    printf("Danh sach: ");
    printList(head);

    // Dem so luong phan tu trong danh sach
    int count = countElements(head);
    printf("So luong phan tu trong danh sach: %d\n", count);

    return 0;
}

