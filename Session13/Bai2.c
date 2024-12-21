#include <stdio.h>
#include <stdbool.h>

// Ham hoan doi hai so nguyen
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Ham thuc hien thuat toan Sap xep chon
void selectionSort(int arr[], int n, bool ascending) {
    for (int i = 0; i < n - 1; i++) {
        int idx = i; // Chi so cua phan tu nho nhat/lon nhat

        for (int j = i + 1; j < n; j++) {
            if (ascending ? (arr[j] < arr[idx]) : (arr[j] > arr[idx])) {
                idx = j;
            }
        }

        // Hoan doi neu can thiet
        if (idx != i) {
            printf("Hoan doi: %d <-> %d\n", arr[i], arr[idx]);
            swap(&arr[i], &arr[idx]);
        }

        // Hien thi mang sau moi lan hoan doi
        printf("Mang sau lan hoan doi %d: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

// Ham hien thi mang
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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

    // Hien thi mang truoc khi sap xep
    printf("Mang ban dau: ");
    printArray(arr, n);

    // Hoi nguoi dung sap xep tang dan hay giam dan
    int choice;
    printf("Nhap 1 de sap xep tang dan, 0 de sap xep giam dan: ");
    scanf("%d", &choice);

    // Sap xep mang
    selectionSort(arr, n, choice == 1);

    // Hien thi mang sau khi sap xep
    printf("Mang sau khi sap xep: ");
    printArray(arr, n);

    return 0;
}
