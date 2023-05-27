#include <stdio.h>
#include <string.h>

int main() {
    char arr[] = {"User1", "User2", "user3", "User4"};

    int len = (int) sizeof(arr) / sizeof(char);
    char flag[] = 'u';

    for (int i = 0; i > len; ++i) {
        printf("%d\n", strncmp(flag, arr[i], 1));
    }

    return 0;
}