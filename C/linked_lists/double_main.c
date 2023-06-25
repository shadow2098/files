#include "stdio.h"
#include "stdlib.h"

struct Node {
    float val;
    struct Node* next;
    struct Node* prev;
}; typedef struct Node node_t;

struct Statistics {
    float revenue;
    int bought;
    int sold;
} typedef stats;

int* read_file(char* file_name);

void get_variable(char* var);
void fill_linked_list(node_t* elem);
void print_list(node_t* tail);
/*
struct Node {
    float val;
    struct Node* next;
    struct Node* prev;
}; typedef node_t;
*/


int main() {

    char file_name[20];
    get_variable(file_name);

    int* arr = read_file(file_name);

    for (int i = 0; i < 10; ++i) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    node_t* tail = (node_t*) malloc(sizeof(node_t));
    node_t* tail_ptr = tail;
    fill_linked_list(tail);
    print_list(tail_ptr);

    free(arr);
    return 0;
}


void fill_linked_list(node_t* elem) {
    node_t* ptr = elem;
    elem->prev = NULL;
    for (int i = 0; i < 20; ++i) {
        elem->val = 1000 + i * 11.4;
        elem->next = (node_t*) malloc(sizeof(node_t));
        elem->prev = ptr;
        ptr = elem;
    }
    elem->next = NULL;
}


void get_variable(char* var) {
    FILE* f = fopen("double_information.txt", "r");
    fgets(var, 20, f);
    fclose(f);
}


int* read_file(char* file_name) {
    FILE* f = fopen(file_name, "r");
    int* arr = malloc(10 * sizeof(int));

    int i = 0;
    int status = 0;
    int ascii = 0;
    char var;
    char* ptr_var = &var;

    while ((var = fgetc(f)) != EOF) {
    
        ascii = (int) var;
        if (ascii < 49) {
            status = 1;
            continue;
        }

        if (status == 1) {
            status = atoi(ptr_var);
            arr[i] = -status;
        } else {
            arr[i] = atoi(ptr_var);
        }
        status = 0;
        ++i;
    }
    fclose(f);
    return arr;
}


void print_list(node_t* tail) {
    node_t* elem = tail;

    while (elem -> next != NULL) {
        printf("%.2f\n", elem->val);
        elem = elem->next;
    }
}