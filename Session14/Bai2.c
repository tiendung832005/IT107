#include <stdio.h>

// Ham tim kiem nhi phan
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Tranh tran so khi left + right

        if (arr[mid] == target) {
            return mid; // Tra ve chi so neu tim thay
        } else if (arr[mid] < target) {
            left = mid + 1; // Tim o nua ben phai
        } else {
            right = mid - 1; // Tim o nua ben trai
        }
    }

    return -1; // Tra ve -1 neu khong tim thay
}
int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14}; // Mang phai duoc sap xep truoc
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Nhap gia tri can tim: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Gia tri %d duoc tim thay tai chi so %d.\n", target, result);
    } else {
        printf("Khong tim thay gia tri %d trong mang.\n", target);
    }

    return 0;
}

