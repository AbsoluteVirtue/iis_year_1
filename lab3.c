#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    
    int array[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("%d\n", array[0][1]);
    printf("%d\n", *((int *)array + 0*3 + 1));

    size_t total = sizeof(array);
    size_t row = sizeof(*array);
    size_t item = sizeof(*(int *) array);

    for (int * p = (int *)array; p < (int *)array + (total / item); ++p) {
        printf("%d\t", *p);
    }

    return 0;
}
