#include <stdio.h>
#include <stdlib.h>


#define N 6
#define M 2


int main(int argc, char const *argv[]) 
{

    int matrix[M][N] = {
        {1, -14, 7, -3, -2, 11},
        {3, -8, 19, -1, 0, 8},
    };

    int i, j, k, t, z, d, Summ, max[N], min[M];

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            if ( matrix[i][j] < 0 ){
                Summ = 0;
                // for(int k = 0; k < M; k++)
                for(int k = 0; k < N; k++) //
                    Summ += matrix[i][k];

                break; //
            }
        printf("Сумма %d",i);
        printf(" строки = %d", Summ);
        printf("\n");
    };

    i=0;
    j=0;
    min[i] = matrix[i][j]; //
    for (i = 0; i < M; ) //
    {
        for ( ; j < N; j++) //
        {
            // min[i] = matrix[i][j];
            if (min[i] > matrix[i][j])
                min[i] = matrix[i][j];
        }
        i += 1; //
        j = 0; //
        min[i] = matrix[i][j]; //
    }

    j = 0;
    for (j = 0; j < N; j++)
    {
        i=0;
        max[j] = matrix[i][j];
        for (i = 0; i < M; i++)
            if (max[j] < matrix[i][j])
                max[j] = matrix[i][j];
    }

    t = min[0];
    for (i = 0; i < M; i++)
        if (t < min[i])
            t = min[i];

    d = max[0];
    for (i = 0; i < N; i++)
        if (d > max[i])
            d = max[i];

    if (d > t) printf("Седловых точек нет \n");
    else printf("Седловые точки = \n");

    for (i = 0; i < M; i++) {
        if (min[i] == t) {
            for (j = 0; j < N; j++) {
                if (max[j] == d)
                {
                    printf(" %d",i);
                    printf(" %d",j);
                    printf("\n");
                }
            }
        }
    }

    return 0;
}
