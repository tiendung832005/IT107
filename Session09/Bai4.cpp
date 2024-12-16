#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    Node* adjList[MAX_VERTICES];
    int numVertices;
} Graph;

void initGraph(Graph* g, int numVertices) {
    g->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        g->adjList[i] = NULL;
    }
}

// Them canh vao do thi
void addEdge(Graph* g, int u, int v) {
    // Them v vao danh sach ke cua u
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = g->adjList[u];
    g->adjList[u] = newNode;

    // Them u vao danh sach ke cua v (vi do thi vo huong)
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = u;
    newNode->next = g->adjList[v];
    g->adjList[v] = newNode;
}

// Thuc hien thuat toan BFS
void bfs(Graph* g, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES], front = 0, rear = 0;

    // Danh dau dinh bat dau la da tham va dua vao hang doi
    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("Thu tu cac dinh duyet BFS: ");

    while (front != rear) {
        // Lay dinh tu hang doi
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Duyet qua cac dinh ke cua dinh hien tai
        Node* temp = g->adjList[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    Graph g;
    int numVertices, numEdges;

    // Nhap so luong dinh va so luong canh
    printf("Nhap so luong dinh cua do thi: ");
    scanf("%d", &numVertices);
    printf("Nhap so luong canh cua do thi: ");
    scanf("%d", &numEdges);

    // Khoi tao do thi
    initGraph(&g, numVertices);

    // Nhap danh sach cac canh
    printf("Nhap danh sach cac canh (moi canh duoc mo ta boi hai dinh):\n");
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        printf("Canh %d: ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(&g, u, v);
    }

    // Nhap dinh bat dau BFS
    int startVertex;
    printf("Nhap dinh bat dau de duyet BFS: ");
    scanf("%d", &startVertex);

    // Thuc hien duyet BFS va in ket qua
    bfs(&g, startVertex);

    return 0;
}

