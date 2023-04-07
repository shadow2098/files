#include <stdio.h>
#include <string.h>

void copy_memory(void* arr1f, void* arrf, int len);


int main() {

	int arr[5] = {500, -20, 489, 2098, 123};
	int len = sizeof(arr) / sizeof(arr[0]);
	int arr1[len];

	copy_memory(arr1, arr, sizeof(arr));


	printf("\nCopied array is ");
	for (int i = 0; i < len; ++i) {
		printf("%d ", arr1[i]);
	}

	return 0;
}


void copy_memory(void* arr1f, void* arrf, int len) {
	char* arr = (char*) arrf;
	char* arr1 = (char*) arr1f;

	for (int i=  0; i < len; ++i) {
		arr1[i] = arr[i];
	}
}

/*
int main() {
	
	char str[] = "apple, orange";
	printf("%s\n", str);

	memcpy(str, &str[7], 6 * sizeof(char));
	printf("%s\n", str);

	memmove(str, &str[7], 6 * sizeof(char));
	printf("%s\n", str);

	return 0;
}
*/
