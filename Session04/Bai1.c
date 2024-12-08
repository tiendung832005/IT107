#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Dinh nghia cau truc node cua danh sach lien ket
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Ham tao danh sach lien ket voi n phan tu
Node* createList(int n, int isRandom) {
    Node *head = NULL, *temp = NULL, *newNode = NULL;
    int value;

    // Tao seed cho viec sinh so ngau nhien
    if (isRandom) {
        srand(time(0));
    }

    for (int i = 0; i < n; i++) {
        newNode = (Node*)malloc(sizeof(Node));
        if (!newNode) {
            printf("K the cap phat bo nho\n");
            return NULL;
        }

        // Nhap du lieu hoac tao du lieu ngau nhien
        if (isRandom) {
            newNode->data = rand() % 100; 
        } else {
            printf("Nhap phan tu thu %d: ", i + 1);
            scanf("%d", &value);
            newNode->data = value;
        }

        newNode->next = NULL;

        // Them node vao cuoi danh sach
        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    return head;
}

// Ham duyet va in danh sach lien ket
void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Ham giai phong bo nho da cap phat cho danh sach lien ket
void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, choice;
    printf("Nhap so luong phan tu cua danh sach lien ket: ");
    scanf("%d", &n);
    
    printf("Nhap 1 de tao danh sach voi so ngau nhien, 0 de nhap thu cong: ");
    scanf("%d", &choice);

    // Tao danh sach lien ket
    Node *head = createList(n, choice);

    // In danh sach lien ket
    printf("Danh sach lien ket: ");
    printList(head);

    // Giai phong bo nho
    freeList(head);

    return 0;
}

