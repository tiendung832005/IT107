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
int recStack[MAX];      


void addEdge(int u, int v) {
    
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;
}


int DFS(int v) {
    visited[v] = 1;      
    recStack[v] = 1;     

    Node* temp = adjList[v];
    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (!visited[connectedVertex]) {
            if (DFS(connectedVertex)) {
                return 1; 
            }
        } else if (recStack[connectedVertex]) {
            return 1; 
        }
        temp = temp->next;
    }

    recStack[v] = 0;     
    return 0;
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
        recStack[i] = 0;
    }

    printf("Nhap danh sach cac canh (dinh u, dinh v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    
    int hasCycle = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (DFS(i)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle) {
        printf("Do thi co chu trinh\n");
    } else {
        printf("Do thi khong co chu trinh\n");
    }

    return 0;
}

