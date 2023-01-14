#include "stdio.h"
#include "stdlib.h"


int main() {
	
	int arr_length = 10;
	int* arr = (int*) malloc(arr_length * sizeof(int));

	for (int i = 0; i < arr_length; ++i) {
    	arr[i] = i;
    	printf("%d\n", arr[i]);
	}

	arr = (int*) realloc(arr, (arr_length - 1) * sizeof(int));

	for (int i = 0; i < arr_length; ++i) {
		printf("%d\n", arr[i]);
	}


	free(arr);
	return 0;
}