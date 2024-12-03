#include<stdio.h>

int main(){
	int n;
	
//	nhap phan tu
printf("Nhap so phan tu cua mang (0 < n <= 100): ");
scanf("%d", &n);

// Kiem tra dk
if( n <= 0 || n > 100) {
	printf("Cac phan tu khong hop le \n");
	return 1;
}
int arr[n]; //Khai bao mang 

// Nhap cac phan tu cho mang
printf("Nhap cac phan tu cua mang: \n");
for(int i =0; i<n;i++){
	printf("Phan tu %d: ", i+1);
	scanf("%d", &arr[i]);
}

int max = arr[0];

//Duyet qua mang de tim phan tu lon nhat
for(int i = 1; i<n;i++){
	if( arr[i] > max){
		max = arr[i];
	}
}
//In ra phan tu lon nhat
printf("Phan tu lon nhat trong mang la: %d\n", max);

return 0;
}
