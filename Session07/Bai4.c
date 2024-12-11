#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;         
    struct Node* next; 
};


struct Queue {
    struct Node* front; 
    struct Node* rear;   
};

// Ham khoi tao mot hang doi trong
void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Ham kiem tra xem hang doi co rong khong
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// Ham them phan tu vao hang doi
void enqueue(struct Queue* q, int value) {
    // Tao mot nut moi
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Loi: Khong the cap phat bo nho!\n");
        return;
    }

    newNode->data = value;  
    newNode->next = NULL;   

    // Neu hang doi rong, ca front va rear deu tro den nut moi
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    // Neu hang doi khong rong, them nut moi vao cuoi
    q->rear->next = newNode;
    q->rear = newNode;
}

// Ham lay phan tu dau tien cua hang doi
int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Loi: Hang doi rong! Khong the lay phan tu dau tien.\n");
        return -1; 
    }
    return q->front->data; 
}

// Ham in trang thai cua hang doi
void printQueueStatus(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong.\n");
    } else {
        printf("Hang doi khong rong.\n");
    }
}
int main() {
    struct Queue q;
    initQueue(&q);

    // Kiem tra trang thai hang doi ban dau
    printf("Trang thai hang doi ban dau: ");
    printQueueStatus(&q);

    // Them phan tu vao hang doi
    enqueue(&q, 10);
    printf("Them 10 vao hang doi. Phan tu dau tien: %d\n", peek(&q));

    enqueue(&q, 20);
    printf("Them 20 vao hang doi. Phan tu dau tien: %d\n", peek(&q));

    enqueue(&q, 30);
    printf("Them 30 vao hang doi. Phan tu dau tien: %d\n", peek(&q));

    // Xoa phan tu khoi hang doi va kiem tra
    int value = peek(&q);
    if (value != -1) {
        printf("Phan tu dau tien trong hang doi: %d\n", value);
    }

    return 0;
}

