#include "stdio.h"
#include "stdlib.h"

int main() {

    FILE *f, *w, *v;
    char text[100];

    f = fopen("test1.txt", "w");
    fprintf(f, "Hello World.");
    fclose(f);

    w = fopen("test1.txt", "r");
    fgets(text, 100, w);
    printf("%s\n", text);
    fclose(w);

    v = fopen("test1.txt", "a");
    fprintf(v, " Apple orange");
    fclose(v);

    w = fopen("test1.txt", "r");
    fgets(text, 100, w);
    printf("%s\n", text);
    fclose(w);

}