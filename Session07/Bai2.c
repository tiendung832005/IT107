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

// khoi tao mot hang doi trong
void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// kiem tra xem hang doi co rong khong
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// them phan tu vao hang doi (enqueue)
void enqueue(struct Queue* q, int value) {
   
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

// xoa phan tu khoi hang doi
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong! Khong the dequeue.\n");
        return -1;
    }

    // Lay gia tri phan tu dau tien trong hang doi
    struct Node* temp = q->front;
    int value = temp->data;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);

    return value;
}

// in tat ca cac phan tu trong hang doi
void printQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong!\n");
        return;
    }

    struct Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    struct Queue q;
    initQueue(&q);

    // Them cac phan tu vao hang doi
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Hang doi sau khi them phan tu: ");
    printQueue(&q);

    // Xoa phan tu khoi hang doi
    int value = dequeue(&q);
    if (value != -1) {
        printf("Phan tu bi xoa: %d\n", value);
    }

    printf("Hang doi sau khi dequeue: ");
    printQueue(&q);

    return 0;
}

