#include<stdio.h>
#include<stdlib.h>
void insertElementArray(int **pArray,int *n,int position,int value);
int main(){
	// mang dong 
	int n;
	int *pArray = NULL;
	int position, value;
	// nhap n
	printf("Moi ban nhap vao so phan tu cua mang ");
	scanf("%d",&n);
	// cap phat bo nho dong 
	pArray = (int*) malloc(n * sizeof(int));
	
	// nhap vao phan tu dau tien cua mang dong 
	//printf("nhap vao phan tu dau tien cua mang dong ");
	//scanf("%d",&pArray[0]);
	//printf("Phan tu dau tien có gia tri la %d ",pArray[0]);
	// Nhap gia tri cho cac phan tu mang 
	for(int i = 0; i < n; i++){
		printf("arr[%d] = ",i);
		scanf("%d",pArray+i);
	}
	// in ra cac gia tri 
	
	for(int i = 0; i < n; i++){
		printf("\n arr[%d] = %d",i,*pArray+i);
	}
	
	printf("Nhap vao vi tri can chen ");
	scanf("%d",&position);
	printf("Nhap vao gia tri can chen ");
	scanf("%d",&value);
	
	insertElementArray(&pArray,&n,position,value);
	printf("\n Sau khi chen ");
	// in ra cac gia tri 
	for(int i = 0; i < n; i++){
		printf(" \n arr[%d] = %d",i,pArray[i]);
	}
	return 0;
}
// trien khai ham them moi phan tu
void insertElementArray(int **pArray,int *n,int position,int value){
	if(position < 0 || position > *n){
		printf("Vi tri can chen khong hop le");
		return;
	}
	// cap phat moi
	*pArray = (int*) realloc(*pArray,(*n + 1) * sizeof(int));
	
	for(int i = *n; i > position; i--){
		(*pArray)[i] = (*pArray)[i-1];
	}
	(*pArray)[position] = value;
	(*n)++;
}
