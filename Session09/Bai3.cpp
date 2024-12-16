#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100


typedef struct {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES]; 
    int adjList[MAX_VERTICES][MAX_VERTICES];    
    int numVertices;  
} Graph;

void initGraph(Graph *g, int numVertices) {
    g->numVertices = numVertices;

    // Khoi tao ma tran ke
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            g->adjMatrix[i][j] = 0;
            g->adjList[i][j] = -1;
        }
    }
}

// Them canh vao ma tran ke
void addEdgeMatrix(Graph *g, int u, int v, int directed) {
    g->adjMatrix[u][v] = 1;
    g->adjMatrix[v][u] = 1;  

    if (directed) {
        g->adjMatrix[v][u] = 0;  
    }
}

// Them canh vao danh sach ke
void addEdgeList(Graph *g, int u, int v, int directed) {
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

// DFS d? quy d? phát hi?n chu k?
int dfsCycleMatrix(int u, int visited[], int parent[], Graph *g) {
    visited[u] = 1;

    for (int v = 0; v < g->numVertices; v++) {
        if (g->adjMatrix[u][v] == 1) {
            if (!visited[v]) {
                parent[v] = u;
                if (dfsCycleMatrix(v, visited, parent, g)) {
                    return 1;
                }
            } else if (v != parent[u]) {
                return 1; 
            }
        }
    }
    return 0;
}

int dfsCycleList(int u, int visited[], int parent[], Graph *g) {
    visited[u] = 1;

    int i = 0;
    while (g->adjList[u][i] != -1) {
        int v = g->adjList[u][i];
        if (!visited[v]) {
            parent[v] = u;
            if (dfsCycleList(v, visited, parent, g)) {
                return 1;
            }
        } else if (v != parent[u]) {
            return 1;
        }
        i++;
    }
    return 0;
}

// Phat hien chu ky trong do thi
int hasCycleGraph(Graph *g, int directed) {
    int visited[MAX_VERTICES] = {0};
    int parent[MAX_VERTICES] = {-1};

    for (int i = 0; i < g->numVertices; i++) {
        if (!visited[i]) {
            if (directed) {
                if (dfsCycleMatrix(i, visited, parent, g)) {
                    return 1; 
                }
            } else {
                if (dfsCycleList(i, visited, parent, g)) {
                    return 1;  
                }
            }
        }
    }
    return 0; 
}

// In ma tran ke
void displayAdjMatrix(Graph *g) {
    printf("Ma tran ke\n");
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// In danh sach ke
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
    int numEdges = 4;
    int directed = 0; g

    
    initGraph(&g, numVertices);

    // Them cac canh vao do thi
    addEdgeMatrix(&g, 0, 1, directed); 
    addEdgeMatrix(&g, 1, 2, directed); 
    addEdgeMatrix(&g, 2, 3, directed); 
    addEdgeMatrix(&g, 3, 0, directed);  

    // Hien thi ma tran ke
    displayAdjMatrix(&g);
    displayAdjList(&g);

    // Phat hien chu ky
    if (hasCycleGraph(&g, directed)) {
        printf("Do thi co chu ky\n");
    } else {
        printf("Do thi khong co chu ky\n");
    }

    return 0;
}

