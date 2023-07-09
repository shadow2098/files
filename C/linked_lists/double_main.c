#include "stdio.h"
#include "stdlib.h"

struct Node {
    float val;
    struct Node* next;
    struct Node* prev;
} typedef node_t;

struct Statistics {
    float revenue;
    int bought;
    int sold;
} typedef stats;


stats link_list_operations(node_t* elem, int* arr);

int* read_file(char* file_name);

void get_variable(char* var);
void fill_linked_list(node_t* elem);
void print_list(node_t* tail);
void free_list(node_t* tail);


int main() {

    char file_name[20];
    get_variable(file_name);

    int* arr = read_file(file_name);

    node_t* tail = (node_t*) malloc(sizeof(node_t));
    // node_t* tail_ptr = tail;
    fill_linked_list(tail);
    // print_list(tail_ptr);

    stats object = link_list_operations(tail, arr);

    printf("Gold bars sold: %d | Gold bars bought: %d | Total revenue: %.2f\n", object.sold, object.bought, object.revenue);

    free(arr);
    free_list(tail);
    printf("\n\nlinked list is freed\n");
    return 0;
}

stats link_list_operations(node_t* elem, int* arr) {
    stats object;
    object.revenue = 0;
    object.bought = 0;
    object.sold = 0;

    int err = 0;
    int status = 0;

    for (int i = 0; i < 10; ++i) {
        if (arr[i] < 0) {
            status = 1;
        }
        if (status == 1) {
            for (int j = 0; j < -arr[i]; ++j) {
                if (elem->prev == NULL) {
                    err = 1;
                    break;
                }
                object.revenue -= elem->val;
                if (object.revenue < 0) {
                    object.revenue += elem->val;
                    err = 2;
                    break;
                }
                elem = elem->prev;
            }
            if (err == 1) {
                printf("Linked list ended\n");
                break;
            } else if (err == 2) {
                printf("Not enough revenue to purchase gold bars\n");
                break;
            }
            object.bought += -arr[i];
            status = 0;
        }
        else {
            for (int j = 0; j < arr[i]; ++j) {
                if (elem->next == NULL) {
                    err = 1;
                    break;
                }
                object.revenue += elem->val;
                elem = elem->next;
            }
            if (err == 1) {
                printf("Linked list ended\n");
                break;
            }
            object.sold += arr[i];
        }
    }
    return object;
}


void fill_linked_list(node_t* elem) {
    elem->prev = NULL;
    for (int i = 0; i < 20; ++i) {
        elem->val = 1000 + i * 11.4;
        elem->next = (node_t*) malloc(sizeof(node_t));
        elem->next->prev = elem;

        elem = elem->next;
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
    char arr_char[] = {'\0', '\0'};

    while ((arr_char[0] = fgetc(f)) != EOF) {
        ascii = (int) arr_char[0];
        if (ascii < 49) {
            status = 1;
            continue;
        }
        if (status == 1) {
            status = atoi(arr_char);
            arr[i] = -status;
        } else {
            status = atoi(arr_char);
            arr[i] = status;
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


void free_list(node_t* tail) {
   node_t* elem;

   while (tail != NULL) {
       elem = tail;
       tail = tail->next;
       free(elem);
    }
}