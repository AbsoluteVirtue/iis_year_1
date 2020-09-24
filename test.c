#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int _compare(const void * a, const void * b) {

    return ( *(int*)a - *(int*)b );
}


void main(int argc, char const *argv[]) {

    int array[3][4] = {
        {1, 3, 8, 5},
        {3, 12, 2, 13},
        {4, 6, 8, 14},
    };

    int copy [12] = {}; 

    int max [] = {1, 1}, res = NULL;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            
            copy[i*4 + j] = array[i][j];

        }
    }

    qsort(copy, 12, sizeof(*copy), _compare);

    for (int i = 1; i < 12; ++i) {
        if (copy[i] == copy[i-1]) {
            res = copy[i];
        }
    }

    return;
}
