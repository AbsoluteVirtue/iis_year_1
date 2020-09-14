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


void print(int _a [], int size) {

    for (int i = 0; i < size; i += 1) {

        printf("%d\t", _a[i]);

    }
}


int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}


int main(int argc, char const *argv[])
{

    int len = argc - 1;

    int a [len];

    int sum = 0;

    int i = 0;
    while (i < len) {

        a[i] = (int)atof(argv[i + 1]);

        if (a[i] > 0) {
            sum += a[i];
        }

        i += 1;
    }

    qsort(a, argc, sizeof(int), compare);

    printf("Sum: %d\n", sum);
    printf("Sorted array: ");
    for (int idx = 0; idx < len; idx += 1) {
        printf("%d,\t", a[idx]);
   }

    return 0;
}
