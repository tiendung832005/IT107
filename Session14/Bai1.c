#include <stdio.h>


int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1;
}
int main() {
    int arr[] = {5, 3, 8, 6, 2, 7, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Nhap gia tri can tim: ");
    scanf("%d", &target);

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        printf("Gia tri %d duoc tim thay tai chi so %d.\n", target, result);
    } else {
        printf("Khong tim thay gia tri %d trong mang.\n", target);
    }

    return 0;
}

