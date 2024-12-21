#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n, bool ascending) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (ascending ? (arr[j] > arr[j + 1]) : (arr[j] < arr[j + 1])) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

       
        if (!swapped) {
            break;
        }
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    
    printf("Nhap so : ");
    scanf("%d", &n);

    int arr[n];

    
    printf("Nhap %d gia tri: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    printf("Sau khi sap xep: ");
    printArray(arr, n);

    
    int choice;
    printf("Nhap 1 thu tu tang dan: ");
    scanf("%d", &choice);

    
    bubbleSort(arr, n, choice == 1);

    
    printf("Sau khi sap xep : ");
    printArray(arr, n);

    return 0;
}

