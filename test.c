#include <stdio.h>
#include <string.h>


void main(int argc, char const *argv[])
{
    int a = 88;
    int * pa = &a;
    int * pz = pa + 1;
    // *pz = 88;
    int r = (pz - pa);

    // int arr [] = {1, 2 ,4, 5};
    // int sa = (&arr)[1] - arr;

    return;
}
