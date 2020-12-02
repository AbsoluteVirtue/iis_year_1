#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct _token 
{
    char * str;
    size_t length;
} token;


int compar_struct(const void * a, const void * b) 
{
    return ((token *)a)->length - ((token *)b)->length;
}


int compar_string(const void * a, const void * b) 
{
    return **(char **)a - **(char **)b;
}


int main()
{ 
    char str[256] = {};
    fgets(str, 256, stdin);
    const char * delimiters = " ,.!?@#$%^&*();:\"\n\t";
    token words [10] = {};

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

    qsort(words, 4, sizeof(token), compar_struct);

    return 0;
}
