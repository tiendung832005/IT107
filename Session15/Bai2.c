#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Khai bao cau truc danh sach ke
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjacencyList[MAX_VERTICES];
bool visited[MAX_VERTICES];

// Ham tao nut moi
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Ham them canh vao do thi
void addEdge(int u, int v) {
   
    Node* newNode = createNode(v);
    newNode->next = adjacencyList[u];
    adjacencyList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjacencyList[v];
    adjacencyList[v] = newNode;
}

// Ham duyet DFS (de quy)
void DFS(int vertex) {
    
    visited[vertex] = true;
    printf("%d ", vertex);

    
    Node* temp = adjacencyList[vertex];
    while (temp) {
        int adjacentVertex = temp->vertex;
        if (!visited[adjacentVertex]) {
            DFS(adjacentVertex);
        }
        temp = temp->next;
    }
}

int main() {
    int V, E, startVertex;

    
    printf("Nhap so dinh: ");
    scanf("%d", &V);
    printf("Nhap so canh: ");
    scanf("%d", &E);

   
    for (int i = 0; i < V; i++) {
        adjacencyList[i] = NULL;
        visited[i] = false;
    }


    printf("Nhap danh sach canh (u, v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    
    printf("Nhap dinh bat dau: ");
    scanf("%d", &startVertex);

    
    printf("Thu tu duyet DFS: ");
    DFS(startVertex);
    printf("\n");

    return 0;
}

