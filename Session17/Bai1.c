#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

// Danh sách ke
typedef struct {
    int adj[MAX][MAX];
    int vertices;
} Graph;

void initGraph(Graph *g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adj[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

void DFS(Graph *g, int v, bool visited[]) {
    printf("%d ", v);
    visited[v] = true;

    for (int i = 0; i < g->vertices; i++) {
        if (g->adj[v][i] == 1 && !visited[i]) {
            DFS(g, i, visited);
        }
    }
}

void BFS(Graph *g, int start, bool visited[]) {
    int queue[MAX], front = 0, rear = 0;
    printf("%d ", start);
    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];

        for (int i = 0; i < g->vertices; i++) {
            if (g->adj[v][i] == 1 && !visited[i]) {
                printf("%d ", i);
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    Graph g;
    int vertices, edges;

    printf("Nhap so luong dinh: ");
    scanf("%d", &vertices);
    printf("Nhap so luong canh: ");
    scanf("%d", &edges);

    initGraph(&g, vertices);

    printf("Nhap cac cap canh (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&g, u, v);
    }

    int start;
    printf("Nhap dinh bat dau: ");
    scanf("%d", &start);

    bool visited[MAX] = {false};
    printf("DFS: ");
    DFS(&g, start, visited);

    printf("\n");

    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
    }

    printf("BFS: ");
    BFS(&g, start, visited);

    return 0;
}

