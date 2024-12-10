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
    stack->top = -1;
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

    // Kiem tra ngan xep co rong hay khong
    if (isEmpty(&stack)) {
        printf("Ngan xep rong.\n");
    } else {
        printf("Ngan xep khong rong.\n");
    }

    return 0;
}

