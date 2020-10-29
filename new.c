#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define N 8


typedef enum {False, True} bool_t;


int main(int argc, char const *argv[])
{
    int A [N] = {-3, -2, -1, 0, 4, 5, 8, 10};

    int B [N] = {3, -4, -5, -7, -10, -20, -24, -30};
    int C [N + N] = {};

    int a = N - 1, b = 0;
    
    for (int i = 0; i < N + N; ++i) {

        if (B[b] >= A[a]) {
            C[i] = B[b++];
        } else if (B[b] <= A[a]) {
            C[i] = A[a--];
        }
    }
    
    return 0;
}



