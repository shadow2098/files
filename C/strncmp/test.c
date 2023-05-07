#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char arr_db[10][20] = {"User1", "User2", "user3", "User4", "User" 
							"user5", "user6", "User7", "Admin", "NONE"};

	char arr_error[10][30];
	char flag[4] = "User";


	for (int i = 0; i < 10; i++) {
		if (strncmp(arr_db[i], flag, 4) == 0) {
			strcpy(arr_error[i], arr_db[i]);
		}
		// printf("%s\n", arr_db[i]);
	}

	for (int i = 0; i < 3; i++) {
		printf("%s\n", arr_error[i]);
	}
	return 0;
}
