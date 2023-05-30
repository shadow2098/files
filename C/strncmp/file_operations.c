#include <stdlib.h>
#include <stdio.h>

#include "file_operations.h"

void get_variable(char* var) {
	FILE *f;
	f = fopen("information.txt", "r");
	fgets(var, 20, f);
	fclose(f);
}

void write_to_file(char* file_name, char** arr, int rows) {
	FILE* f;
	f = fopen(file_name, "w");

	for (int i = 0; i < rows; ++i) {
		fprintf(f, "%s",arr[i]);
	}
	fclose(f);
}