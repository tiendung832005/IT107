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

int arr[n];

//Nhap cac phan tu cho mang
printf("Nhap cac phan tu cua mang:\n");
for (int i = 0;i<n;i++){
	printf("Phan tu %d: ", i+1);
	scanf("%d", &arr[i]);
}

//Sap xep mang theo thu tu tang dan (Dung thuat toan sap xep noi bot)
for (int i=0;i<n-1;i++){
	for (int j=0;j<n-i-1;j++){
		if(arr[j] >arr[j+1]){
//			Hoan doi arr[j] va arr[j+1]
			int temp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = temp;
		}
		
	}
}
//In ra mang da sap xep
printf("Mang sau khi sap xep la: [");
for(int i=0; i<n;i++){
	printf("%d", arr[i]);
	if(i < n-1){
		printf(", ");
	}
}
printf("]\n");

return 0;
}
