#include <stdio.h>

int bubble_sorting();

int main() {

	//int arr[] = {-34, 4, -55, 38, -8, -44, 64, 27, 48, -70};
	bubble_sorting();


	return 0;
}

int bubble_sorting() {

	int lenght = 0;

	int arr[] = {-34, 4, -55, 38, -8, -44, 64, 27, 48, -70};


	lenght = sizeof(arr) / sizeof(int);
	printf("%d\n", lenght);

	printf("size is %d\n", lenght);

	int i;
	int j;
	for (i=0; i < lenght; i++) {
		//printf("%d\n", i);
		for (j=0; j < lenght-1; j++) {
			//printf("%d\n", j);

			if (arr[j] > arr[j + 1]) {
				int a = arr[j];
				int b = arr[j + 1];

				arr[j] = b;
				arr[j + 1] = a;

			}
		}

	}

	for (i=0; i < lenght; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;

	}

