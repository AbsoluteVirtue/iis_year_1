#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int _compare(const void * a, const void * b) {

    return (int)ceil( *(float*)a - *(float*)b );
}


void main(int argc, char const *argv[]) {

    float array_lit [] = {67., -90., 45., 78., -13., -456., 4.};

    qsort(array_lit, sizeof(array_lit) / sizeof(*array_lit), sizeof(*array_lit), _compare);

    return;
}
