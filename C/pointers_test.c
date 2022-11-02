#include "stdio.h"

int main() {
	int a = 15;
	int* pointer = &a;

	printf("%p\n", pointer);
	return 0;
}