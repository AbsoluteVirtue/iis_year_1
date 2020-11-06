#include <stdio.h>
#define M 4
#define N 5
#include <stdlib.h>

int main(){
    int k=2,n=1;
    //printf("Vvedi 1 esli sdvig v pravo,vvedi 2 esli sdvig v niz :");scanf("%d\n",&k);
    int A[N][M] = {{1,2,3,4},     
                   {5,6,7,8},
                   {9,1,2,3},
                   {4,5,1,5},
                   {5,7,2,3}
                   };
    int C[N][M];
    int cache = A[0][0];
    int flag;              
    //printf("Vedi na skoliko doljen sdvinutisa element:");scanf("%d\n",&n);
    if (k == 1){
        for (int i = 0;i<N;i++){
            for (int j = 0;j<M;j++){
                C[(((j+n)/M)+i)%N][(j+n)%M] = A[i][j];
            }            
        }
    }else if (k == 2){
        for (int i = 0;i<M;i++){
            for (int j = 0;j<N;j++){
                C[(j+n)%N][(((j+n)/N)+i)%M] = A[j][i];
            }
        }
    }else{
        printf("vvedi k 1 ili 2");
        return 0;
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    return 0;
}