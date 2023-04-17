#include <stdio.h>
#include <string.h>

int compare_str(char* str, char* str1);


int main() {
	char str1[] = "abcd";
	char str2[] = "a\0bcd";
	int res, res1;

	res = strcmp(str1, str2);
	printf("real strcmp(str1, str2) = %d\n", res);

	res1 = compare_str(str1, str2);
	printf("artificial compare_str(str1, str2) = %d\n", res1);

	return 0;
}


int compare_str(char* str1, char* str2) {
	int i = 0;
	while ((str1[i] != '\0') || (str2[i] != '\0')) {
		if (str1[i] != str2[i]) {
			int res = (int) str1[i] - (int) str2[i];
			return res;
		}
		++i;
	}
	return 0;
}