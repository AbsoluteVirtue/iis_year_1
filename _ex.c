#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iso646.h>


#define N 8


int _PtFuncCompare(const void * a, const void * b) {

    return (*(int *)a - *(int *)b);
}


void _print_array(int * X, int len) {

    for(int * p = X; p < X + len; ++p) {
        printf("%d", *p);
    }

}


void print_array(int X[], int len) {

    for(int i = 0; i < len; ++i) {
        printf("%d", X[i]);
    }

}


void swap(int* a, int* b) { // меняет местами элементы
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void shift(int* beg, int* end) {
    while (beg + 1 != end) {
        swap(beg, beg + 1);
        ++beg;
    }
}
void stable_partition(int* box, int size) {
    int i;
    int* end = box + size;
    int* last = end - 1;
    int stop = size;
    for (i = 0; i < stop; ++i) {
        while (0 == box[i]) {
            shift(&box[i], end);
            last = 0;
            if (!--stop) break;
        }
    }
}


int main(int argc, char const *argv[])
{

    int A[N] = {0, -2, 4, 0, -4, 3, -5, 1};
    int B[N] = {3, -4, 5, 7, 1, -2, 4, 0};
    int R[N + N] = {};
    int min = INT_MAX;
    for (int j = 0; j < N + N; j++)
    {
        int i = 0, k = 0;
        min = INT_MAX;
        int flag = -1;
        for (; i < N; i++)
        {
            if (A[i] < min) {
                min = A[i];
                k = i;
                flag = 1;
            } else if (B[i] < min) {
                min = B[i];
                k = i;
                flag = 0;
            }
        }
        if (flag != -1) {
            if (flag) {
                A[k] = INT_MAX;
            } else {
                B[k] = INT_MAX;
            }
        }
        
        R[j] = min;
    }

    return 0;
}
