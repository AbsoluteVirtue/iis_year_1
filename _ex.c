#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iso646.h>
#include <string.h>
#include <time.h>


void printn(char c, int n) {
    while ( --n >=0 ) 
    {
        putchar(c);
    }
}


void reverse(int * head, int * tail) {
    if ( head < tail ) {
        *head = *head + *tail;
        *tail = *head - *tail;
        *head = *head - *tail;
        reverse(head + 1, tail - 1);
    }
}


char* Reverse(char text[]) {
    char* begin = text;
    char* end = text + strlen(text) - 1;
    char tmp;
 
    for (; begin < end; ++begin, --end) {
        tmp = *begin;
        *begin = *end;
        *end = tmp;
    }
 
    return text;
}

#define N 10
#define M 2


int main(int argc, char const *argv[]) 
{
    int i, j, sum, count=0, A[N][N];
    // FILE *fp;
    // fp = fopen("z.dat", "r");
    // for ( i = 1; i < N-1; i ++ )
    //     for ( j = 1; j < N-1; j ++ )
    //         if ( 0 == fscanf(fp,"%d",&A[i][j]) ) 
    //         {
    //             puts("Не хватает данных");
    //             fclose ( fp ); 
    //             return 1; 
    //         }
    // fclose ( fp );

    srand(time(NULL));
    for ( i = 1; i < N-1; i ++ )
        for ( j = 1; j < N-1; j ++ )
        {
            A[i][j] = rand() % 100;
        }

	for(i=0;i<N;i++){
		j=0;
		A[j][i]=1000000;
		}
    //1column
	for(i=0;i<N;i++){
		j=0;
		A[i][j]=1000000;
		}
	//lastcolumn
	for(i=0;i<N;i++){
		A[i][N-1]=1000000;
		}
	//last string
	for(i=0;i<N;i++){
		A[N-1][i]=1000000;
		}	

    printf("Исходный массив A[%d][%d]={\n",N-2,N-2);	
    for ( i = 1; i < N-1; i ++ ) { 
        for ( j = 1; j < N-1; j ++ ) 
            printf ( "%d ", A[i][j] ); 
            printf("\n"); 
    }
    printf("}");
        for(i=1;i<N-1;i++){
            for(j=i+1;j<N-1;j++)
            sum+=abs(A[i][j]);
    }
	printf("\n\nСумма модулей элементов выше главной диагонали = %d\n",sum);	
    for(i=1;i<N-1;i++){
		for(j=1;j<N-1;j++)
		    if(A[i][j]<A[i][j-1] && A[i][j]<A[i][j+1] 
            && A[i][j]<A[i+1][j] && A[i][j]<A[i-1][j] 
            && A[i][j]<A[i+1][j-1] && A[i][j]<A[i+1][j+1]
            && A[i][j]<A[i-1][j-1] && A[i][j]<A[i-1][j+1])
                count++;
	}
    printf("\nКол-во локальных минимумов матрицы = %d",count);
}
