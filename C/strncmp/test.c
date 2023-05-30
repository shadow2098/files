#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// void print_matrix(char** matrix, int rows, int cols);
// char** create_matrix(int rows, int cols);
// void free_matrix(char** arr, int rows);

int main() {

    int arr[10];

    int len = (int) sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", len);

    for (int i = 0; i < 10; ++i) {
        arr[i] = i;
    }

    for (int i = 0; i < 10; ++i) {
        printf("%d\n", arr[i]);
    }

    return 0;
}

    /*
    int rows = 10;
    int cols = 20;
    char** arr = create_matrix(rows, cols);

    print_matrix(arr, rows, cols);

    free_matrix(arr, rows);

    return 0;
}
*/
/*
	char arr_db[10][20] = {"User1", "User2", "user3", "User4", "User",
							"user5", "user6", "User7", "Admin", "NONE"};

	char arr_error[10][20];
	char flag[] = "User";

	for (int i = 0; i < 10; i++) {
		if (strncmp(arr_db[i], flag, 4) == 0) {
			strcpy(arr_error[i], arr_db[i]);
		} else {
            arr_error[i][0] = '\0';
        }
	}

	for (int i = 0; i < 10; i++) {
		printf("%s\n", arr_error[i]);
	}
	return 0;
}


char** create_matrix(int rows, int cols) {
    char** arr = (char**) malloc(rows * sizeof(char));

    for (int i = 0; i < rows; ++i) {
        arr[i] = (char*) malloc(cols * sizeof(char));
    }
    return arr;
}


void print_matrix(char** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("\n");
        for (int j = 0; j < cols; j++) {
            printf("%c ", arr[i][j]);
        }
    }
    printf("\n");
}


void free_matrix(char** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}
*/