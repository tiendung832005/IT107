#include <stdio.h>
#include <string.h>


struct SinhVien {
    char ten[50];
    int diem;
};

int main() {
    int n, i;
    char tenCanTim[50];
    int found = 0;

    
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    
    if (n <= 0) {
        printf("So luong sinh vien khong hop le!\n");
        return 1;
    }

    
    struct SinhVien dsSinhVien[n];

    
    printf("Nhap thong tin sinh vien (ten va diem):\n");
    for (i = 0; i < n; i++) {
        printf("Sinh vien %d:\n", i + 1);
        printf("  Ten: ");
        scanf("%s", dsSinhVien[i].ten);
        printf("  Diem: ");
        scanf("%d", &dsSinhVien[i].diem);
    }

   
    printf("\nNhap ten sinh vien can tim: ");
    scanf("%s", tenCanTim);

    
    for (i = 0; i < n; i++) {
        if (strcmp(dsSinhVien[i].ten, tenCanTim) == 0) {
            printf("Diem cua %s la: %d\n", tenCanTim, dsSinhVien[i].diem);
            found = 1; 
            break;
        }
    }

    
    if (!found) {
        printf("Khong tim thay sinh vien.\n");
    }

    return 0;
}

