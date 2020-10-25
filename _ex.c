#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iso646.h>
#include <string.h>
#include <time.h>


#define N 8


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


int main(int argc, char const *argv[]) {

    srand(time(0));

    int A [N] = {-3, -2, -1, 0, 4, 5, 8, 10};

    char * res = Reverse("1234");

    int B [N] = {3, -4, -5, -7, -10, -20, -24, -30};
    int C [N + N] = {};

    // int a = N - 1, b = 0;
    
    // for (int i = 0; i < N + N; ++i) {

    //     if (B[b] >= A[a]) {
    //         C[i] = B[b++];
    //     } else if (B[b] <= A[a]) {
    //         C[i] = A[a--];
    //     }
    // }

    return 0;
}
