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

// Ham tim kiem phan tu trong danh sach
int search(struct Node* head, int key) {
    int index = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            return index;
        }
        temp = temp->next;
        index++;
    }

    return -1;
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
    int n, value, searchValue, index;

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
        addAtEnd(&head, value); 
    }

    printf("Danh sach lien ket ban dau:\n");
    printList(head);  

    // Nhap gia tri can tim kiem
    printf("Nhap gia tri can tim kiem: ");
    scanf("%d", &searchValue);

    // Thuc hien tim kiem
    index = search(head, searchValue);

    if (index != -1) {
        printf("Phan tu %d duoc tim thay tai vi tri %d.\n", searchValue, index);
    } else {
        printf("Phan tu %d khong ton tai trong danh sach.\n", searchValue);
    }

    return 0;
}

