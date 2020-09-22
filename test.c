#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


void print_array_string(char _a []) {

    int size = strlen(_a);

    char * ap = (char *) malloc(size + 1);

    for (int j = 0; j < size; j += 1) {
        ap[j] = _a[j];
    }
    ap[size] = '\0';

    for (int i = 0; i < size + 1; i += 1) {
        printf("%c\t", ap[i]);
    }

    free(ap);

}


int main(int argc, char const *argv[]) {

    return 0;
}
