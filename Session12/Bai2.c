#include <stdio.h>

int main() {
    int n, i, min;

    // Nhap so luong phan tu
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    // Kiem tra mang
    if (n <= 0) {
        printf("Kich thuoc mang khong hop le!\n");
        return 1;
    }

    // Tao mang so nguyen
    int arr[n];

    // Nhap cac phan tu cua mang
    printf("Nhap %d phan tu cua mang:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // khoi tao phan tu nho nhat
    min = arr[0];

    // Tim phan tu nho nhat
    for (i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // In ra phan tu nho nhat
    printf("Phan tu nho nhat trong mang la: %d\n", min);

    return 0;
}

