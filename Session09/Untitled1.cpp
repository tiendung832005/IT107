#include<stdio.h>
#define v 4;

void addEdge(int matrix[v][v], int i, int j){
	matrix[i][j] = 1;
	matrix[j][i] = 1;
}

void printMatrix(int matrix[v][v]){
	for(int i = 0; i<v;i++){
		for(int j =0; j < v; j++){
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int matrix[v][v];
	addEdge(matrix,0,1);
	addEdge(matrix,0,2);
	addEdge(matrix,1,2);
	addEdge(matrix,2,3);
	
	printMatrix(matrix)
	return 0;
}
