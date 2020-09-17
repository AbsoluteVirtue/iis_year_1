#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


void input() {

    char line[256];
    int i;
    if (fgets(line, sizeof(line), stdin)) {
        if (1 != sscanf(line, "%d", &i)) {
            printf("input error!");
            return;
        }
    }
}


void array_allocation (int size) {

    char * pa = (char *) malloc(size + 1);

    if (pa != NULL) {

        for(int i = 0; i < size; i += 1) {
            char ch;
            if (scanf("%c", &ch) == 1) {
                pa[i] = ch;
            }
        }
        pa[size] = '\0';

        printf("%s", pa);
    }

    free(pa);

}


void strcopy(char * p, char * new, int N) {

    for (int i = 0; i<=N; i += 1) {

        if (!p[i]) break;

        new[i] = p[i];
    }
    new[N] = '\0';
}


void fib(const int n) {

    int res[n + 1];
    res[0] = 0;
    res[1] = 1;
    for (int i = 2; i <= n; i += 1) {
        res [i] = res[i-1] + res[i-2];
        printf("%i\t", res[i]);
    }
}


int main(int argc, char const *argv[]) {

    fib(19);

    const int N = 4;

    char * new = (char *) malloc(N + 1);
    
    strcopy("string", new, N);

    for (int i = 0; i < 4; i += 1) {
        printf("%c\t", new[i]);
    }

    free(new);

    int arr [] = {1, 2 ,4, 5};

    int sa = (&arr)[1] - arr;

    int a = 88;
    int * pa = &a;
    int * pz = pa + 1;
    // *pz = 88;
    int r = (pz - pa);

}
