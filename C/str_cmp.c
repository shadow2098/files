#include <stdio.h>
#include <string.h>

int compare_str(char* str1, char* str2);


int main() {
	char str1[100];
	printf("Max cap for string lengts is 100\n");
	printf("First string for comparison - ");
	scanf("%s", str1);

	char str2[100];
	printf("Second string - ");
	scanf("%s", str2);
	printf("\n");

	int res, res1;

	res = strcmp(str1, str2);
	printf("real strcmp(str1, str2) = %d\n", res);

	res1 = compare_str(str1, str2);
	printf("artificial compare_str(str1, str2) = %d\n", res1);

	return 0;
}


int compare_str(char* str1, char* str2) {
	int str1_len = strlen(str1);
	int str2_len = strlen(str2);
	int min_len = 0;

	if (str1_len < str2_len) {
		min_len = str1_len;
	} else {
		min_len = str2_len;
	}

	for (int i = 0; i < min_len + 1; ++i) {
		if (str1[i] == str2[i]) {
			continue;
		} else {
			return (int) (str1[i] - str2[i]);
		}
	}
	return 0;
}