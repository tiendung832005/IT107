#include<stdio.h>

int sum(int n, int m){
	if(n==m){
		return n;
	}else{
		return n + sum(n+1, m);
	}
}

int main(){
	int n,m;
	
	printf("Nhap so nguyen n: ");
	scanf("%d", &n);
	
	printf("Nhap so nguyen m (m>=n): ");
	scanf("%d", &m);
	
	if(n>m){
		printf("n phai nho hon m.\n");
	}else{
		int result = sum(n,m);
		printf("Tong cac so tu %d den %d la: %d", n,m, result);
	}
	return 0;
}
