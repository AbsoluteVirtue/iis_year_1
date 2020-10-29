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

#define N 6
#define M 2


int main(int argc, char const *argv[]) 
{

    return 0;
}
