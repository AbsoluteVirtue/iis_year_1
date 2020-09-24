#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    
    int array[][3] = {
        {1, 9, -3},
        {0, 100, 10},
        {10, -8, 9}
    };

    printf("%d\n", array[0][1]);
    printf("%d\n", *((int *)array + 0*3 + 1));

    size_t total_size = sizeof(array);
    size_t row_size = sizeof(*array);
    size_t item_size = sizeof(*(int *) array);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d\t",array[i][j]);
        }
        printf("\n");
    }

    for (int * p = (int *)array; p < (int *)array + (total_size / item_size); ++p) {
        printf("%d\n", *p);
    }

    int counter = 0;

    for (int i = 0; i < 3; ++i) {
        int sum = 1;
        for (int j = 0; j < 3; ++j) {
            sum *= array[i][j];
        }
        if (sum) {
            counter++;
        }
    }

    for (int i = 0; i < 3; ++i) {
        int flag = 1;
        for (int j = 0; j < 3; ++j) {
            if (!array[i][j]) {
                flag = 0;
                break;
            }
        }
        if (flag) counter++;
    }
    
    printf("%d", counter);

    return 0;
}
