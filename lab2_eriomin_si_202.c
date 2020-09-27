#include <stdio.h>

const int  N=5;


int main(int argc, char* argv[]){
    int i;
    int u=0;
    int k=0;
    int MaxA=0;
    int MaxB=0;
    int A[N];
    float result;

    for (int i = 0; i < N; i++)
    {
        printf("A[%d]=", i);
        scanf("%d", &A[i]);
    }

    for (i = 0; i < N; i++){ 
        if (A[i] > MaxA)
            MaxA = A[i];
    }

    for (i = 0; i<N; i++) {
        if(A[i] == MaxA)
            MaxB++;
    }

    for (i = 0; i<N; i++){
        if(A[i] == MaxA)
            k = k + MaxA;
    }

    u = k / MaxB;

    printf( "Максимальное значение:%d\n", MaxA);

    printf("Кол-во макс элементов :%d\n" , MaxB);

    printf("Cреднее арифметическое максимумов :%d\n" , u);
}
