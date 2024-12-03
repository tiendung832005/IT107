#include<stdio.h>

int main(){
	int n, x;
	
//	Nhap so phan tu cua mang
printf("Nhap so phan tu cua mang (0 < n <= 100): ");
scanf("%d", &n);

// Kiem tra dieu kien n
if (n <= 0 || n > 100){
	printf("So phan tu khong hop le\n");
	return 1;
}
int arr[n]; //Khai bao mang voi n phan tu

// Nhap cac phan tu cho mang
printf("Nhap cac phan tu cua mang:\n");
for (int i=0; i<n; i++){
	printf("Phan tu %d:", i+1);
	scanf("%d", &arr[i]);
}

//Nhap so x can tim
printf("Nhap so x can dem: ");
scanf("%d", &x);

// Dem so lan xuat hien cua x trong mang
int count = 0;
for(int i=0;i<n;i++){
	if(arr[i] == x){
		count++;
	}
}

//In ra ket qua
printf("So %d xuat hien %d lan trong mang.\n", x, count);

return 0;

}
