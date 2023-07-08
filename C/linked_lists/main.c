#include <stdio.h>
#include <stdlib.h>



struct Node {
    float val;
    struct Node* next;
} typedef node_t;

struct Statistics {
    float revenue;
    int amount;
} typedef stats;


stats link_list_operations(node_t* elem, int* arr);

int* read_file(char* file_name);

void fill_linked_list(node_t* elem);
void get_variable(char* var);
void print_list(node_t* head);
void free_list(node_t* head);




int main() {

    char file_name[20];
    get_variable(file_name);

    int* arr = read_file(file_name);

    node_t* head = (node_t*) malloc(sizeof(node_t));
    node_t* head_ptr = head;
    fill_linked_list(head);

    print_list(head_ptr);

    stats object = link_list_operations(head, arr);
    printf("Total revenue - %.2f$, amount of gold bars sold - %d\n", object.revenue, object.amount);

    free_list(head);
    free(arr);
    printf("Linked list is freed\n");

    return 0;
}



stats link_list_operations(node_t* elem, int* arr) {
    stats object;
    object.revenue = 0;
    object.amount = 0;
    int err = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < arr[i]; ++j) {
            if (elem -> next == NULL) {
                err = 1;
                break;
            }
            object.revenue += elem -> val;
            elem = elem -> next;
        }
        if (err == 1) {
            printf("Linked list ended");
            break;
        }
        object.amount += arr[i];
    }
    return object;
}


void fill_linked_list(node_t* elem) {
    for (int i = 0; i < 20; ++i) {
        elem -> val = 1000 + i * 11.4;
        elem -> next = (node_t*) malloc(sizeof(node_t));
        elem = elem -> next;
    }
    elem->next = NULL;
}


void print_list(node_t* head) {
    node_t* elem = head;

    while (elem -> next != NULL) {
        printf("%.2f\n", elem->val);
        elem = elem->next;
    }
}


void get_variable(char* var) {
    FILE* f = fopen("information.txt", "r");
    fgets(var, 20, f);
    fclose(f);
}


int* read_file(char* file_name) {
    FILE* f = fopen(file_name, "r");
    int* arr = malloc(10 * sizeof(int));

    int i = 0;
    char var;
    char* ptr_var = &var;
    while ((var = fgetc(f)) != EOF) {
        arr[i] = atoi(ptr_var);
        printf("%d\n", arr[i]);
        ++i;
    }
    fclose(f);
    printf("\n\n\n\n\n\n\n");
    return arr;
}


void free_list(node_t* head) {
   node_t* elem;

   while (head != NULL) {
       elem = head;
       head = head->next;
       free(elem);
    }

}