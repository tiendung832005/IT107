#include<stdio.h>
#include<lib.h>

typedef struct Node{
	int data;
	struct Node*next;
	struct Node*prev;
}Node;

Node* createNode(int data){
	// cap phat bo nho
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->next =  NULL;
	newNode->prev = NULL;
	return newNode;
}

void insertHead(Node**head, int data){
	// tao node moi
	Node* newNode = create(data);
	newNode->next = *head;
	if(*head != NULL){
		(*head)->prev = newNode;
	}
	*head = newNode;
}

//duyet danh sach
void printList(Node* head){
	Node* temp = head;
	printf("NULL");
	while(temp != NULL){
		printf("<-----%d<------>", temp->data);
		temp = temp->next;
	}
}
int main(){
	do{
		printf("\n=========MENU=========\n");
		printf("1. Them 1 phan tu vao dau danh sach");
		printf("2. Hien thi \n");
		printf("3. Thoat \n");
		printf("Moi ban chon tu 1 den 3");
		int choice;
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Moi ban nhap vao gia tri cho pahn tu ");
				scanf("%d", &value);
				insertHead(&head, value);
				break;
			case 2:
				printflist(head);
			case 3:
		}
	}
}
