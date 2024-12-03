#include<stdio.h>

int main(){
	// khai bao mang 1 chieu  
	int array[5];
	// khai bao va gan gia tri 
	int arrayInit[] = {1,3,4};
	
	// truy cap vao phan tu thong qua chi muc (index) 
	//printf("array[%d] = ",0);
	//scanf("%d",&array[0]);
	
	// in ra gia tri cua phan tu dau tien trong mang array 
	printf("Gia tri phan tu dau tien %d",array[0]);
	
	// in ra gia tri thu 3 cua mang arrayInit 
	printf("in ra gia tri thu 3 cua mang arrayInit %d ",arrayInit[2]);
	
	// nhap xuat voi mang ket hop vong lap for(i) 
	for(int i = 0; i < 3; i++){
		printf(" \n array[%d] = %d",i,arrayInit[i]);	
	}
	printf("/n nhap vao cac gia tri phan tu mang array");
	// nhap cac gia cho phan tu mang array 
	for(int i = 0; i < 5; i++){
		printf("arr[%d] = ",i);
		scanf("%d",&array[i]);
	}
	// hien thi cac gia phan tu mang array 
	printf("\n hien thi cac gia phan tu mang array ");
	for(int i = 0; i < 5; i++){
		printf(" \n array[%d] = %d",i,array[i]);	
	}
	return 0;
}
