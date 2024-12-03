#include <stdio.h>

int main() {
    int n, m;
    
    // Nhap so luong phan tu cua mang 1
    printf("Nhap so luong phan tu cua mang 1: ");
    scanf("%d", &n);
    
    int array1[n];
    
    // Nhap mang 1
    printf("Nhap cac phan tu cua mang 1:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array1[i]);
    }
    
    // Nhap so luong phan tu cua mang 2
    printf("Nhap so luong phan tu cua mang 2: ");
    scanf("%d", &m);
    
    int array2[m];
    
    // Nhap mang 2
    printf("Nhap cac phan tu cua mang 2:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &array2[i]);
    }
    
    // Gop 2 mang vao
    int mergedArray[n + m];
    for (int i = 0; i < n; i++) {
        mergedArray[i] = array1[i];
    }
    for (int i = 0; i < m; i++) {
        mergedArray[n + i] = array2[i];
    }
    
    // In ra ket qua
    printf("Mang sau khi gop la:\n");
    for (int i = 0; i < n + m; i++) {
        printf("%d ", mergedArray[i]);
    }
    
    return 0;
}

