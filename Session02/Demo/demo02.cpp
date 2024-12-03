#include<stdio.h>
#include<stdlib.h>

void in(int *n);
int main(){
	
	int n = 10;
	in(&n);
	printf("Gia tri n %d",n);
	return 0;
}

void in(int *n){
	(*n)++;
}
