#include <stdio.h>
#include <time.h>

int main() {

    int index;
    printf("Insert index: ");
    scanf("%d", &index);

    int num_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = index; i < 10 - 1; i++) {
        num_arr[i] = num_arr[i + 1];
    }


    for (int i = 0; i < 9; i++) {
        printf("%d\n", num_arr[i]);
    }

    return 0;
}