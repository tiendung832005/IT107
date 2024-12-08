#include <stdio.h>
#include <stdlib.h>

// Dinh nghia cau truc cho node cua danh sach lien ket
struct Node {
    int data;
    struct Node* next;
};

// Ham them phan tu vao cuoi danh sach
void addAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Ham xoa phan tu dau danh sach
void deleteFromHead(struct Node** head) {
    if (*head == NULL) {
        printf("Danh sach da rong.\n");
        return;
    }

    struct Node* temp = *head;
    *head = temp->next;  // Chuyen dau danh sach sang phan tu tiep theo
    free(temp);  // Giai phong bo nho cua node cu
}

// Ham hien thi danh sach lien ket
void printList(struct Node* head) {
    if (head == NULL) {
        printf("Danh sach rong.\n");
        return;
    }
    
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;  // Khoi tao danh sach lien ket rong
    int n, value;

    printf("Nhap so luong phan tu n (0 <= n <= 1000): ");
    scanf("%d", &n);

    if (n < 0 || n > 1000) {
        printf("So luong phan tu khong hop le.\n");
        return 0;
    }

    // Nhap vao cac phan tu va them vao danh sach
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        addAtEnd(&head, value);  // Them phan tu vao cuoi danh sach
    }

    printf("Danh sach lien ket ban dau:\n");
    printList(head);  // Hien thi danh sach ban dau

    // Xoa phan tu dau tien trong danh sach
    deleteFromHead(&head);

    printf("Danh sach sau khi xoa phan tu dau:\n");
    printList(head);  // Hien thi danh sach sau khi xoa phan tu dau

    return 0;
}

