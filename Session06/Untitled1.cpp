#include<stdio.h>
#include<stdlib.h>
#define MAX 100;
// cau truc ngan xep
typedef struct Stack{
	int array[MAX];
	int top;
}, Stack;

// Khoi tao stack rong
void inital(Stack* stack){
	stack->top = -1;
}

//kiem tra stack co rong hay khong
int isEmpty(Stack* stack){
	if(stack->top == -1){
		return 1;
	}
	return 0;
}

//kiem tra ngan xep co bi day hay khong
int isFull(Stack* stack){
	if(stack->top >= MAX - 1){
		return 1;
	}
	return 0;
}

void push(Stack* stack, int value){
	if(isFull(stack) == 1){
		printf("Xin loi ngan xep da day");
		return;
	}
	stack ->array[++(stack->top)] = value;
}
void printfStack(Stack* stack){
	for(int i = 0, i< MAX, i++){
		printf("%d\n", stack->array[i]);
	}
}
int main(){
	do{
		printf("=========MENU========");
		printf("1. Them phan tu vao ngan xep \n");
		printf("2. In ra ngan xep");
		printf("0. Thoat \n");
		printf("Moi ban chon 0-2");
		int choice;
		scanf("%d", &choice);
		switch(choice){
			case 0:
				exit 0;
			case 1:
				printf("Nhap vao gia tri can them");
				scanf("%d", &value);
				
		}
	}
	return 0;
}
