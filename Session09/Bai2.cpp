#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

void initAdjMatrix(int matrix[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            matrix[i][j] = 0;
        }
    }
}

void addEdge(int matrix[MAX_VERTICES][MAX_VERTICES], int u, int v) {
    matrix[u][v] = 1;
    matrix[v][u] = 1;
}

// Kiem tra tinh doi xung cua ma tran ke
int isSymmetric(int matrix[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

// In ma tran ke
void displayAdjMatrix(int matrix[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    printf("Ma tran ke\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numVertices, numEdges;
    int matrix[MAX_VERTICES][MAX_VERTICES];

    // Nhap so luong dinh va so luong canh
    printf("Nhap so luong dinh cua do thi: ");
    scanf("%d", &numVertices);

    printf("Nhap so luong canh cua do thi: ");
    scanf("%d", &numEdges);

    // Khoi tao ma tran ke
    initAdjMatrix(matrix, numVertices);

    // Nhap danh sach cac canh va them vao ma tran ke
    printf("Nhap danh sach cac canh cua do thi (moi canh duoc mo ta boi hai dinh):\n");
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        printf("Canh %d: ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(matrix, u, v);
    }

    // In ma tran ke
    displayAdjMatrix(matrix, numVertices);

    // Kiem tra tinh doi xung cua ma tran ke
    if (isSymmetric(matrix, numVertices)) {
        printf("Ma tran ke la doi xung\n");
    } else {
        printf("Ma tran ke khong doi xung\n");
    }

    return 0;
}

