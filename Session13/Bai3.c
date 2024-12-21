#include <stdio.h>
#include <stdbool.h>

// Ham hoan doi hai so nguyen
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Ham thuc hien thuat toan Sap xep chon
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[idx]) {
                idx = j;
            }
        }
        if (idx != i) {
            swap(&arr[i], &arr[idx]);
        }
    }
}

// Ham hien thi mang
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Ham tim kiem nhi phan
int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
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

    // Sap xep mang
    selectionSort(arr, n);

    // Hien thi mang sau khi sap xep
    printf("Mang sau khi sap xep: \n");
    printArray(arr, n);

    // Tim kiem phan tu
    int x;
    printf("Nhap phan tu can tim: ");
    scanf("%d", &x);

    int result = binarySearch(arr, n, x);
    if (result != -1) {
        printf("Phan tu %d duoc tim thay tai vi tri %d\n", x, result + 1);
    } else {
        printf("Khong tim thay phan tu %d trong mang\n", x);
    }

    return 0;
}

