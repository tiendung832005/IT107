#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int adjList[MAX_VERTICES][MAX_VERTICES];  
    int numVertices;  // So luong dinh
} Graph;

void initGraph(Graph *g, int numVertices) {
    g->numVertices = numVertices;

    // Khoi tao ma tran ke va danh sach ke
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            g->adjMatrix[i][j] = 0;
            g->adjList[i][j] = -1;
        }
    }
}

// Them canh vao do thi
void addEdge(Graph *g, int u, int v, int directed) {
    g->adjMatrix[u][v] = 1;
    g->adjMatrix[v][u] = 1;  
    
    // Neu do thi co huong, chi can cap nhat mot chieu
    if (directed) {
        g->adjMatrix[v][u] = 0;
    }

    // Them vao danh sach ke
    int i = 0;
    while (g->adjList[u][i] != -1) {
        i++;
    }
    g->adjList[u][i] = v;
    
    i = 0;
    while (g->adjList[v][i] != -1) {
        i++;
    }
    g->adjList[v][i] = u; 

   
    if (directed) {
        g->adjList[v][i] = -1;
    }
}

// Hien thi ma tran ke
void displayAdjMatrix(Graph *g) {
    printf("Ma tran ke\n");
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Hien thi danh sach ke
void displayAdjList(Graph *g) {
    printf("\nDanh sach ke\n");
    for (int i = 0; i < g->numVertices; i++) {
        printf("%d: ", i);
        int j = 0;
        while (g->adjList[i][j] != -1) {
            printf("%d ", g->adjList[i][j]);
            j++;
        }
        printf("\n");
    }
}

int main() {
    Graph g;
    int numVertices = 4;

    // Khoi tao do thi voi 4 dinh
    initGraph(&g, numVertices);

    // Them cac canh cho do thi
    addEdge(&g, 0, 1, 0);  
    addEdge(&g, 0, 2, 0);
    addEdge(&g, 1, 2, 0); 
    addEdge(&g, 1, 3, 0);  

    // Hien thi ma tran ke va danh sach ke
    displayAdjMatrix(&g);
    displayAdjList(&g);

    return 0;
}

