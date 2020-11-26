#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct _string {
    char * str;
    size_t length;
} string;

int compar(const void * a, const void * b) 
{
    return ((string *)a)->length - ((string *)b)->length;
}

int main() { 
    char str[256] = {};
    fgets(str, 256, stdin);
    if (str[strlen(str)] != ' ') 
        str[strlen(str)] = ' ';

    const char * delimiters = " ,.!?@#$%^&*();:'\"\n\t";

    string words [10] = {};

    char *token = strtok(str, delimiters);
    int i = 0;
    while(token) {
        words[i].str = token;
        words[i].length = strlen(token);
        token = strtok(NULL, delimiters);
        i++;
    }

    size_t maxlen = 0;
    for (size_t i = 0; i < 10; i++)
    {
        if(words[i].str) {
            if (words[i].length > maxlen) maxlen = words[i].length;
        }
    }
    
    qsort(words, 4, sizeof(string), compar);

    return 0;
}
