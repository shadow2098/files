/*
Написать программу, 
которая выделяет память под массив, 
заполняет этот массив случайными числами 
и выводит элементы этого массива. 
Вывод элементов массива нужно реализовать 
    с помощью отдельной функции. 
Необходимо реализовать два вида функций - 
    в одну функцию передавать массив как обычно через указатель, 
    в другую функцию - передавать адрес указателя на массив 
    и внутри этой функции реализовать такую же логику для вывода 
        элементов массива
*/
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