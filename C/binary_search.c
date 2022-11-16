#include "stdio.h"

int binary_search_fun(int* arr, int arr_lenght, int requested_num);

int main () {


	int num;
	printf("Number you want to find - ");
	scanf("%d", &num);

	int arr[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
		 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
			 21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
				31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
					41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
						51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
							61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
								71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
									81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
										91, 92, 93, 94, 95, 96, 97, 98, 99, 100};
	
	int arr_lenght = sizeof(arr) / sizeof(int);
	binary_search_fun(arr, arr_lenght, num);

	return 0;
}



int binary_search_fun(int* arr, int arr_lenght, int requested_num) {

	int max_num = arr_lenght;
	int min_num = 1;
	int avg = ((max_num + min_num) / 2);

	for (int i = 0; i < arr_lenght; i++) {
		printf("%d\n", avg);
		if (arr[avg] == requested_num) {
			printf("Requested number is %d\n", arr[avg]);
			break;
		} else if (arr[avg] > requested_num) {
			max_num = avg - 1;
			avg = ((max_num + min_num) / 2);
		} else if (arr[avg] < requested_num) {
			min_num = avg + 1;
			avg = ((max_num + min_num) / 2);
		}
	}

	return 0;

}
