#include <stdlib.h>
#include <stdio.h>

#include "get_data.h"

void get_variable(char* var) {
	FILE *f;
	f = fopen("information.txt", "r");
	fgets(var, 20, f);
}
