#include <stdio.h>
#include <stdlib.h>
#define MAX 100


typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}


Node* adjList[MAX];
int visited[MAX]; 


void addEdge(int u, int v) {
    
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    
    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

void DFS(int v) {
    visited[v] = 1; 
    Node* temp = adjList[v];

    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (!visited[connectedVertex]) {
            DFS(connectedVertex);
        }
        temp = temp->next;
    }
}

int main() {
    int V, E;
    printf("Nhap so dinh: ");
    scanf("%d", &V);
    printf("Nhap so canh: ");
    scanf("%d", &E);

    
    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    printf("Nhap danh sach cac canh (dinh u, dinh v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    
    DFS(0);

    
    int isConnected = 1;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            isConnected = 0;
            break;
        }
    }

    if (isConnected) {
        printf("Do thi lien thong\n");
    } else {
        printf("Do thi khong lien thong\n");
    }

    return 0;
}

