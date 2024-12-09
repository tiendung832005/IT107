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

// Ham xoa phan tu cuoi cung trong danh sach lien ket doi
void deleteLast(struct Node** head) {
    // Kiem tra neu danh sach rong
    if (*head == NULL) {
        return;
    }

    // Neu danh sach chi co mot phan tu
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    // Di chuyen den phan tu cuoi cung
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Xoa phan tu cuoi cung
    temp->prev->next = NULL;
    free(temp);
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
    struct Node* head = createNode(1);
    head->next = createNode(3);
    head->next->prev = head;
    head->next->next = createNode(5);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(7);
    head->next->next->next->prev = head->next->next;

    // In danh sach truoc khi xoa phan tu cuoi cung
    printf("Danh sach truoc khi xoa phan tu cuoi cung: ");
    printList(head);

    // Xoa phan tu cuoi cung
    deleteLast(&head);

    // In danh sach sau khi xoa phan tu cuoi cung
    printf("Danh sach sau khi xoa phan tu cuoi cung: ");
    printList(head);

    return 0;
}

