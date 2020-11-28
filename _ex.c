#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iso646.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>


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


int main(int argc, char const *argv[]) 
{
    
}
