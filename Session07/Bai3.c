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
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Loi: Khong the cap phat bo nho\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;   

    
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    
    q->rear->next = newNode;
    q->rear = newNode;
}

// Ham xoa phan tu khoi hang doi
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

    // Them cac phan tu vao hang doi
    enqueue(&q, 10);
    printf("Them 10 vao hang doi. Trang thai hang doi: ");
    printQueueStatus(&q);

    enqueue(&q, 20);
    printf("Them 20 vao hang doi. Trang thai hang doi: ");
    printQueueStatus(&q);

    enqueue(&q, 30);
    printf("Them 30 vao hang doi. Trang thai hang doi: ");
    printQueueStatus(&q);

    // Xoa phan tu khoi hang doi
    int value = dequeue(&q);
    if (value != -1) {
        printf("Lay ra phan tu: %d. Trang thai hang doi sau dequeue: ", value);
        printQueueStatus(&q);
    }

    // Xoa tiep phan tu khoi hang doi
    value = dequeue(&q);
    if (value != -1) {
        printf("Lay ra phan tu: %d. Trang thai hang doi sau dequeue: ", value);
        printQueueStatus(&q);
    }

    // Xoa tiep phan tu khoi hang doi
    value = dequeue(&q);
    if (value != -1) {
        printf("Lay ra phan tu: %d. Trang thai hang doi sau dequeue: ", value);
        printQueueStatus(&q);
    }

    // Thu xoa phan tu khi hang doi rong
    value = dequeue(&q);
    if (value == -1) {
        printf("Khong the dequeue, hang doi da rong.\n");
    }

    return 0;
}

