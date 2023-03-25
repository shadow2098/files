#include <stdio.h>
#include <string.h>


int main() {
	char str[20];
	int len;

	char str1[20];
	int len1;

	char str_copy[20];

	printf("Enter your name: ");
	fgets(str, 20, stdin);

	printf("My full name is %s\n",str);


	printf("Enter anything: ");
	fgets(str1, 20, stdin);

	fputs(str1, stdout);


// len
	printf("\n\n\nLength\n");
	len = strlen(str);
	printf("Length of first string - %d\n", len);
	len1 = strlen(str1);
	printf("Length of second string - %d\n", len1);


// Copy
	printf("\nCopied string is: %s\n", strcpy(str_copy, str));


// concatenation
	printf("\n\n\nConcatenation\n");
	printf("Concatenated string - %s", strcat(str, str1));


// comparison
	printf("\n\n\nComparison\n");
	int res = strcmp(str, str1);

	if (res == 0) {
	printf("Strings are equal\n");
	} else{
	printf("Strings are not equal\n");
	}


	return 0;
}