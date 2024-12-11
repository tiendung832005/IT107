#include<stdio.h>
#define MAX 5

typedef struct Queue{
	int array[MAX];
	int front;
	int rear;
};
//khoi tao hang doi
void initalQueue(Queue* queue){
	queue->front = -1;
	queue->rear = -1;
}

//kiem tra hang doi rong
int isEmpty(Queue* queue){
	if(queue->front == -1){
		return 1;
	}
	return 0;
}

// kiem tra hang doi day
int isFull(Queue* queue){
	if(queue->rear == MAX - 1){
		return 1;
	}
	return 0
}

//Enqueue ( Them phan tu vao cuoi hang doi)
void enqueue(Queue* queue, int value){
	if(isFull(queue) == 1){
		printf("Xin loi het slot r");
		return;
	}
		if(isEmpty(queue) == 1){
			queue->front = 0;
		}
		queue->rear++;
		queue->array[queue->rear]  = value;
	
}

//display queue
void displayQueue(Queue* queue){
	for (int i = queue->front, i <= queue->rear, i++){
		printf("%d\t", queue->array[i]);
	}
}
int main(){
	Queue queue;
	initalQueue(&queue);
	int value;
	do{
		printf("\n=========MENU=======\n");
		printf("0. Thoat\n");
		printf("1. Them phan tu vao cuoi hang doi \n");
		printf("2. Hien thi hang doi\n");
		printf("Moi lua chon");
		int choice;
		scanf("%d", &choice);
		switch()
	}while(1==1)
}
