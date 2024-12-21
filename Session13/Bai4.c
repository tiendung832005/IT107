#include <stdio.h>

// Ham hien thi mang
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Ham thuc hien thuat toan Sap xep chen
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Di chuyen cac phan tu lon hon key ve sau
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        // Hien thi mang sau moi lan chen
        printf("Mang sau lan chen %d: ", i);
        printArray(arr, n);
    }
}

int main() {
    int n;

    // Nhap kich thuoc mang
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    int arr[n];

    // Nhap cac phan tu cua mang
    printf("Nhap %d phan tu: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Hien thi mang ban dau
    printf("Mang ban dau: ");
    printArray(arr, n);

    // Sap xep mang
    insertionSort(arr, n);

    // Hien thi mang sau khi sap xep
    printf("Mang sau khi sap xep: ");
    printArray(arr, n);

    return 0;
}

