#include<stdio.h>

int main(){
	int n,k;
	
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
// Nhap phan tu can xoa
printf("Nhap phan tu can xoa: ");
scanf("%d", &k);

//Tim phan tu trong mang va xoa no
int found=0;
for(int i =0; i<n;i++){
	if(arr[i] == k){
		found=1; //Tim thay phan tu k
		//Di chuyen cac phan tu phia sau phan tu k mot vi tri ve trc
		for (int j=i; j<n-1;j++){
			arr[j] =arr[j+1];
		}
		n--;
		break;
	}
}
//Kiem tra neu k tim thay k
if(found == 0 ){
	printf("Khong tim thay phan tu");
}else{
	//In ra mang sau khi xoa phan tu
	printf("Mang sau khi xoa la: [");
	for(int i =0; i<n;i++){
		printf("%d", arr[i]);
		if(i < n-1){
			printf(", ");
		}
	}
	printf("]\n");
}
return 0;
}
