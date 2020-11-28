#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct _token 
{
    char * str;
    size_t length;
} Token;

int compar(const void * a, const void * b) 
{
    return ((Token *)a)->length - ((Token *)b)->length;
}

int main()
{ 
    char str[256] = {};
    fgets(str, 256, stdin);
    const char * delimiters = " ,.!?@#$%^&*();:\"\n\t";
    Token words [10] = {};

    char * token = strtok(str, delimiters);
    int i = 0;
    while(token)
    {
        words[i].str = token;
        words[i].length = strlen(token);
        token = strtok(NULL, delimiters);
        i++;
    }

    size_t maxlen = 0;
    for (size_t i = 0; i < 10; i++)
    {
        if(words[i].str)
        {
            if (words[i].length > maxlen)
            {
                maxlen = words[i].length;
            }
        }
    }
    
    qsort(words, 4, sizeof(Token), compar);

    return 0;
}
