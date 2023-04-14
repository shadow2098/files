#include <stdio.h>
#include <string.h>

int compare_str(char* str, char* str1);


int main() {
	char str[] = "abcd\0";
	char str1[] = "abcdef";
	int res, res1;

	res = strcmp(str, str1);
	printf("real strcmp(str, str1) = %d\n", res);

	res1 = compare_str(str, str1);
	printf("artificial compare_str(str, str1) = %d\n", res1);

	return 0;
}


int compare_str(char* str, char* str1) {
	int i = 0;
	while (str[i] == str1[i]) {
		++i;
	}
	int res = (int) str[i] - (int) str1[i];

	return res;
}