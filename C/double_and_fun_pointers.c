#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void single_pointer(int* arr, int len);
void double_pointer(int** arr, int len);


int main() {

    int len = 8;

    int* arr = (int*) malloc(len * sizeof(int));
    if (arr == NULL) {
        printf("Issue while allocation of memory");
        return 0;
    }

    srand(time(NULL));
    for (int i = 0; i < len; ++i) {
        arr[i] = rand() % 80;
    }


    (*single_pointer) (arr, len);
    printf("\n\n\n\n\n");
    (*double_pointer) (&arr, len);


    return 0;
}




void single_pointer(int* arr, int len) {
    printf("Single pointer:\n");

    for (int i = 0; i < len; ++i) {
        printf("%d\n", arr[i]);
    }
}


void double_pointer(int** arr, int len) {
    printf("Double pointer:\n");

    for (int i = 0; i < len; ++i) {
        printf("%d\n", (*arr)[i]);
    }
}