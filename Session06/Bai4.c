#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 

// Dinh nghia cau truc ngan xep
typedef struct {
    int arr[MAX_SIZE];  
    int top;           
} Stack;

// Khoi tao ngan xep
void initStack(Stack *stack) {
    stack->top = -1;  // Ngan xep rong
}

// Kiem tra ngan xep co rong khong
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Them phan tu vao ngan xep
void push(Stack *stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Ngan xep day! Khong the them phan tu.\n");
    } else {
        stack->arr[++stack->top] = value;
    }
}

// Thuc hien thao tac peek de xem gia tri cua phan tu tren cung
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong! Khong co phan tu tren cung.\n");
        return -1;  // Tra ve gia tri loi
    } else {
        return stack->arr[stack->top];
    }
}

// In ra trang thai cua ngan xep
void printStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong!\n");
    } else {
        printf("Cac phan tu trong ngan xep tu tren xuong duoi:\n");
        for (int i = stack->top; i >= 0; i--) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    Stack stack;
    initStack(&stack);

    int n, value;

    // Nhap so luong phan tu can them vao ngan xep
    printf("Nhap so luong phan tu can them vao ngan xep (khong qua 100): ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("So luong phan tu khong hop le! Vui long nhap lai.\n");
        return 1;
    }

    // Them phan tu vao ngan xep
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        push(&stack, value);
    }

    // In ra trang thai ngan xep
    printStack(&stack);

    // Thuc hien thao tac peek de xem gia tri phan tu tren cung
    int topValue = peek(&stack);
    if (topValue != -1) {
        printf("Phan tu tren cung cua ngan xep: %d\n", topValue);
    }

    return 0;
}

