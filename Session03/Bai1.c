#include<stdio.h>

int factorial(int n){
	if(n ==0){
		return 1;
	}else{
		return n * factorial(n-1);
	}
}

int main(){
	int n;
	printf("Nhap so nguyen duong n: ");
	scanf("%d", &n);
	
	if(n<0){
		printf("Vui long nhap dung so nguyen duong \n");
	}else{
		printf("Giai thua cua %d la: %d\n", n, factorial(n));
	}
	return 0;
}
