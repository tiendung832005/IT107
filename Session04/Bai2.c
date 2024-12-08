#include <stdio.h>
#include <stdlib.h>

// Dinh nghia cau truc
struct Node {
    int data;
    struct Node* next;
};

// Ham them phan tu vao dau danh sach
void addAtHead(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Ham hien thi danh sach lien ket
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;  // Khoi tao danh sach lien ket
    int n, value;

    printf("Nhap so luong phan tu n (0 <= n <= 1000): ");
    scanf("%d", &n);

    if (n < 0 || n > 1000) {
        printf("So luong phan tu khong hop le.\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        addAtHead(&head, value);  // Them phan tu vao dau danh sach
    }

    printf("Danh sach lien ket sau khi them phan tu:\n");
    printList(head);  // Hien thi danh sach

    return 0;
}

