#include <stdio.h>

int main() {
    int n, i, max;

    // Nhap kich thuoc mang
    printf("Nhap kich thuoc mang: ");
    scanf("%d", &n);

    // Tao mang so nguyen
    int arr[n];

    // Nhap cac phan tu cua mang
    printf("Nhap %d phan tu cua mang:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Khoi tao phan tu lon nhat la phan tu dau tien
    max = arr[0];

    // tim phan tu lon nhat
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // In ra phan tu lon nhat
    printf("Phan tu lon nhat trong mang la: %d\n", max);

    return 0;
}

