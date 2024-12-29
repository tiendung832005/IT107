#include<stdio.h>
// ham duyet theo chieu sau DFS

int visited[v];
int graph[v][v];

void DFS(int v, int n){
	printf("%d", v);
	visted[v] = 1;
	for(int i =0; 1 < n; i++){
		if(visited[i] == 0 && graph[v][i] == 1){
			DFS(i,n);
		}
	}
}
int main(){
	int visited[v];
	return 0;
}
