#include <stdio.h>
#include <stdlib.h>


int _compare(const void * a, const void * b) {

    return ( abs(*(int *)(a)) - abs(*(int *)(b)) );
}


int main(int argc, char const *argv[])
{
    int array_lit [] = {67, -90, 0, 78, -13, -456, 0};

    int min = 0;
    int k = 0;
    for (int i = 0; i < 7; ++i) {
        if (array_lit[i] < array_lit[min]) {
            min = i;
        }

        if (!array_lit[i]) {
            k += 1;
        }

        if (array_lit[i] % 2) {
            printf("%d is odd\n", array_lit[i]);
        } else {
            printf("%d is even\n", array_lit[i]);
        }
    }

    int sum = 0;
    for ( ;min < 7; printf("%d", min++)) {
        sum += array_lit[min];
    }

    qsort(array_lit, 7, sizeof(*array_lit), _compare);

    return 0;
}
