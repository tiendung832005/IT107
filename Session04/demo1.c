#include<stdio.h>
#include<stdlib.h>
//dinh nghia 1 node
typedef struct Node{
	int data; //phan du lieu cua node
	struct Node* next; // con tro tro den node tiep theo
	
} Node;

// Tao Node moi
Node* createNode(int value){
	// cap phat bo nho
	Node* newNode = (Node*) malloc(sizeof(Node));
	// Gan data cho node
	newNode->data = value;
	// gan phan link
	newNode->next = NULL;
	return newNode;
}

//them phan tu vao dau list
void insertHead(Node** head, int value){
	//tao node moi
	Node* newNode = createNode(value);
	// tro node mou den head
	newNode->next = *head;
	// cap nhat head tro den node moi
	*head = newNode;
}
//duyet danh sach
void printList(Node* head){
	Node* temp = head;
	while(temp != NULL){
		printf("%d-->", temp->data);
		temp = temp->next;
	}
}
int main(){
	Node* head=NULL;
	//theo mot phan tu vao dau danh sach
	printf("Moi ban nhap vao phan tu dau: \n");
	int value;
	scanf("%d", &value);
	insertHead(&head, value);
	
	//in ra
	printf("danh sach \n");
	printList(head);
	do{
		printf("\n======================MENU==================\n");
		printf("\n1. Them phan tu vao dau: ");
		printf("\n2. Xem danh sach: ");
		printf("\n3. Thoat");
		printf("\nMoi ban chon");
		int choice;
		scanf("%d", &choice);
		switch(choice){
			case 1:
				//theo mot phan tu vao dau danh sach
				printf("Moi ban nhap vao phan tu dau: ");
				scanf("%d", &value);
				insertHead(&head, value);
				break;
			case 2: 
				//in ra
				printf("Danh sach: \n");
				printList(head);
				break;
			case 3:
				exit(0);
			default:
				printf("vui long chon lai");
		}
	}while(1==1);
		
	
	
	return 0;
}
