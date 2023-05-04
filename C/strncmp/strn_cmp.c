#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "get_data.h"


/*
Считать данные из файла, 
	в котором на каждой строке находится никнейм пользователя.
Посчитать какое количество никнеймов начинается на 
	заданную последовательность символов 
		(то есть предполагается 
			что эту заданную последовательность символов 
				можно менять в коде)
*/
void read_file(char* file_name, char* text);


int main() {

	char file_name[20];
	get_variable(file_name);
	// printf("%s\n", file_name);


	char text[100];
	read_file(file_name, text);


	printf("%s\n", text);

	return 0;
}

void read_file(char* file_name, char* text) {
	FILE *f = fopen(file_name, "r");


	// char text[255];
	if (f == NULL) {
		printf("Unable to open file!\n");
	}
	else {
		while (fgets(text, 100, f) != NULL) {
			printf("%s", text);
		}
	}

	fclose(f);
}