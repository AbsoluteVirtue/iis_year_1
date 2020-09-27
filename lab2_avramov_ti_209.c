#include <stdio.h>
#include <math.h>
int main(int argc, char* argv[])
{
    const int MAX_ELEMENTS = 12;
    float m[MAX_ELEMENTS] = {88, -44, 55, 0, 9, -56, -34, 123, 5, 67};
    float sum = 0;
    float result = 1;
    int iMax, iMin , i , j , k   ;
    // for (int i = 0; i < MAX_ELEMENTS; i++)
    // {
    //     printf("m[%d] = ", i);
    //     scanf("%f", &m[i]);
    // }
    iMin = iMax = 0;
    for ( i = 0; i < MAX_ELEMENTS; i++) 
    {
        if (m[i] > 0)
            sum += m[i];

        if (fabs (m[i]) > fabs (m[iMax])) 
            iMax = i;
        if ( fabs (m[i]) < fabs (m[iMin])) 
            iMin = i;                
    }

    if ( iMax<iMin) {
        k=iMin ;
        iMin = iMax  ;
        iMax=k ;
    }
    for (i = iMin + 1; i < iMax; ++i) {
        result *= m[i];
    }   
    printf("\nСумма положитнльных элементов = %.2f\n", sum);
    printf("Результат = %.2f\n\n", result);
    for ( i = 0; i < MAX_ELEMENTS; i++)
    {
        for ( j = i + 1; j < MAX_ELEMENTS; j++)
        {
            if (m[i] < m[j])
            {
                result = m[i];
                m[i] = m[j];
                m[j] = result;
            }
        }
    }       
    printf("Отсортированный массив:\n");
    for (  i = 0; i < MAX_ELEMENTS; printf("%.2f ", m[i++]));
    return 0;
}