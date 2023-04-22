#include <stdio.h>
#include <string.h>

int compare_str(char* str1, char* str2);


int main() {
	char str1[] = "abcd";
	char str2[] = "abc";
	int res, res1;

	res = strcmp(str1, str2);
	printf("real strcmp(str1, str2) = %d\n", res);

	res1 = compare_str(str1, str2);
	printf("artificial compare_str(str1, str2) = %d\n", res1);

	return 0;
}


int compare_str(char* str1, char* str2) {
	int len = (int) (sizeof(str1) - sizeof(str2));
	// printf("%d\n", len);

	if (len > 0) {
		for (int i = 0; i < ((int) sizeof(str1)); ++i) {
			if (str1[i] == str2[i]) {
				continue;
			} else {
				// printf("First IF - %d\n", (int) (str1[i] - str2[i]));
				return (int) (str1[i] - str2[i]);
			}
		}
	} else if (len < 0) {
		for (int i = 0; i < ((int) sizeof(str2)); ++i) {
			if (str1[i] == str2[i]) {
				continue;
			} else {
				// printf("ELSE IF - %d\n", (int) (str1[i] - str2[i]));
				return (int) (str1[i] - str2[i]);
			}
		}
	} else {
		for (int i = 0; i < ((int) sizeof(str2)); ++i) {
			if (str1[i] == str2[i]) {
				continue;
			} else {
				// printf("ELSE - %d\n", (int) (str1[i] - str2[i]));
				return (int) (str1[i] - str2[i]);
			}
		}
	}
	return 0;
}