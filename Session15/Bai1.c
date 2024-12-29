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

// Ham duyet BFS
void BFS(int startVertex) {
    int queue[MAX_VERTICES], front = 0, rear = 0;

   
    visited[startVertex] = true;
    queue[rear++] = startVertex;

    printf("Thu tu duyet BFS: ");

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        
        Node* temp = adjacencyList[currentVertex];
        while (temp) {
            int adjacentVertex = temp->vertex;

            if (!visited[adjacentVertex]) {
                visited[adjacentVertex] = true;
                queue[rear++] = adjacentVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
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

    
    BFS(startVertex);

    return 0;
}

