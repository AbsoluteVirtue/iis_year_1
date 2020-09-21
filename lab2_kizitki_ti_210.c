#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define MAX_ELEMENTS 8


int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}


int main(int argc, char* argv[])
{
    int n, i, j;
    float m[MAX_ELEMENTS], result = 1;
    int iMax, iMin, MaxMod;

    for (int i = 0; i < MAX_ELEMENTS; i++)
    { 
        printf("m[%d] = ", i); scanf("%f", &m[i]);
    }

    int score = 0, C=0, p=1;

    printf("Enter a value:");
    scanf("%d", &C);

    iMax=0;
    iMin=0;

    for (i = 0; i < MAX_ELEMENTS; i++)
    {
        if (m[i] > C) {
            score++;
        } 
    }
    printf("The number of digits that are greater than %d: %d\n", C, score);

    for (i = 0; i < MAX_ELEMENTS; i++)
    {
        if (m[i] > m[iMax]) {
            iMax = i;
            iMin=0;
        } else if (m[i] < m[iMin]) {
            iMin = i;
            iMax=0;
        } 
    }

    if (iMax == MAX_ELEMENTS-1)
        printf("Product = 0"); 
    else
    {
        if (iMin==0)
        {
            p=1;
            for (i=iMax;i<MAX_ELEMENTS;i++)
                p=p*m[i];
        }
        else 
            for (i=iMin;i<MAX_ELEMENTS;i++)
                p=p*m[i];
    
        printf("Product of array elements = %d\n", p);
    }

    printf("Sort in ascending order:");
    qsort( m, n, sizeof(int), cmp );

    for(i = 0 ; i < n; i++) { 
        printf("%f ", m[i]);
    }

    return 0;
 }