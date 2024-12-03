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

//Dao nguoc mang
int left = 0, right = n-1;
while (left < right){
	//Hoan doi phan tu tai vi tri left va right
	int temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
	
//	Di chuyen chi so vao trong
left++;
right--;
}

//In ra mang dao nguoc
printf("Mang sau khi dao nguoc la: [");
for (int i=0;i<n;i++){
	printf("%d", arr[i]);
	if(i< n-1){
		printf(", ");
		
	}
}
printf("]\n");
return 0;
}
