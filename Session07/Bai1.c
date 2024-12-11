#include <stdio.h>
#include <stdlib.h>

// Dinh nghia cau truc cua nut trong danh sach lien ket
struct Node {
    int data;           // Du lieu cua phan tu
    struct Node* next;  // Con tro den phan tu ke tiep
};

// Dinh nghia cau truc cua hang doi
struct Queue {
    struct Node* front;  // Con tro den phan tu dau tien trong hang doi
    struct Node* rear;   // Con tro den phan tu cuoi cung trong hang doi
};

// Ham khoi tao mot hang doi trong
void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;  // Hang doi ban dau rong
}

// Ham kiem tra xem hang doi co rong khong
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// Ham them phan tu vao hang doi (enqueue)
void enqueue(struct Queue* q, int value) {
    // Tao mot nut moi
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Loi: Khong the cap phat bo nho!\n");
        return;
    }

    newNode->data = value;  // Gan gia tri cho nut moi
    newNode->next = NULL;    // Nut moi se khong co phan tu ke tiep

    // Neu hang doi rong, ca front va rear deu tro den nut moi
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    // Neu hang doi khong rong, them nut moi vao cuoi
    q->rear->next = newNode;
    q->rear = newNode;
}

// Ham xoa phan tu khoi hang doi (dequeue)
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong!\n");
        return -1;  // Tra ve gia tri khong hop le
    }

    // Lay gia tri phan tu dau tien trong hang doi
    struct Node* temp = q->front;
    int value = temp->data;

    // Di chuyen front sang phan tu ke tiep
    q->front = q->front->next;

    // Neu hang doi tro nen rong, can dat rear ve NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }

    // Giai phong bo nho cua nut da xoa
    free(temp);

    return value;
}

// Ham in tat ca cac phan tu trong hang doi
void printQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong!\n");
        return;
    }

    struct Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);  // In ra gia tri cua phan tu
        temp = temp->next;  // Di chuyen den phan tu tiep theo
    }
    printf("\n");
}
int main() {
    struct Queue q;
    initQueue(&q);  // Khoi tao hang doi trong

    // Them cac phan tu vao hang doi
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    // In cac phan tu trong hang doi
    printf("Cac phan tu trong hang doi: ");
    printQueue(&q);

    // Xoa phan tu khoi hang doi (dequeue)
    printf("Phan tu bi xoa: %d\n", dequeue(&q));

    // In lai cac phan tu trong hang doi sau khi dequeue
    printf("Cac phan tu trong hang doi sau khi dequeue: ");
    printQueue(&q);

    return 0;
}

