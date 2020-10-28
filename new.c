#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef enum {False, True} boolean_t;

void print_dyn_array(int * A, int N) {
    for (int i = 0; i < N; ++i) {
        printf("%d\n", A[i]);
    }
}


int main(int argc, char const *argv[])
{
    int * A = (int *)calloc(3, sizeof(int));
    for (int i = 0; i < 3; ++i) {
        *(A + i) = i + 1;
    }

    print_dyn_array(A, 3);

    free(A);
    
    return 0;
}



