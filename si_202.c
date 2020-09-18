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

void single_pass_min_2(int * arr, int size) {

    int tmp_0 = arr[0];
    int tmp_1 = arr[1];

    for (int i = 2; i < size; ++i) {
        if (arr[i] < tmp_0) {
            if (tmp_1 > tmp_0) {
                tmp_1 = tmp_0;
            }
            tmp_0 = arr[i];
        } else if (arr[i] < tmp_1 && arr[i] != tmp_0) {
            tmp_1 = arr[i];
        }
    }

}


int main(int argc, char const *argv[]) {

    int a = 88;
    int * pa = &a;
    int * pz = pa + 1;
    // *pz = 88;
    int r = (pz - pa);

    // int arr [] = {1, 2 ,4, 5};
    // int sa = (&arr)[1] - arr;

}
