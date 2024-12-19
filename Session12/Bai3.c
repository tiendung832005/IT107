#include <stdio.h>

int main() {
    int n, i, isSymmetric = 0;

    
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    
    if (n <= 0) {
        printf("Kich thuoc mang khong hop le!\n");
        return 1;
    }

   
    int arr[n];

    
    printf("Nhap %d phan tu cua mang:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    printf("Cac cap phan tu doi xung:\n");
    for (i = 0; i < n / 2; i++) {
        if (arr[i] == arr[n - i - 1]) {
            printf("Cap doi xung: (%d, %d)\n", arr[i], arr[n - i - 1]);
            isSymmetric = 1; 
        }
    }

    
    if (!isSymmetric) {
        printf("Mang khong co phan tu doi xung.\n");
    }

    return 0;
}

