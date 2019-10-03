#include<stdlib.h>
#include<stdio.h>


int main()
{
	int N;
	printf("Please enter N:\n");
	scanf("%d", &N);
	
	int *arr = (int*) calloc(N, sizeof(int));

	for(int i = 0; i < N; i++){
		*(arr+i) = i;	
	}

	printf("The array:\n");

	for(int i = 0; i < N; i++){
		printf("%d", *(arr+i));
	}

	printf("\n");
	free(arr);

	return 0;
}
