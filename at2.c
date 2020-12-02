#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 80
#define ROWS 4


int has_str(char * src_str, char * cmp_str)
{
    char * items [ROWS] = {};

    char * tmp_str = (char *)malloc(strlen(src_str) + 1);
    strcpy(tmp_str, src_str);

    char * token = strtok(tmp_str, ",");
    int i = 0;
    while (token != NULL) 
    {
        items[i++] = token;
        token = strtok(NULL, ",");
    }

    free(tmp_str);

    char * fmt_str;
    sprintf(fmt_str, "%s,%s", items[0], items[1]);

    if (!strcmp(fmt_str, cmp_str))
    {
        return 1;
    }

    return 0;
}


void _strncpy(char * dest, const char * src, size_t count)
{
    for (size_t i = 0; i < count && i < strlen(src); i++)
    {
        dest[i] = src[i];
    }
    dest[(count > strlen(src)) ? strlen(src) : count] = '\0';
}


int _atoi(const char * src) 
{
    int res = 0;
    char buf[80] = {};
    size_t k = 0;
    for (size_t i = 0; i < strlen(src); i++)
    {
        if (isdigit(src[i]))
        {
            buf[k++] = src[i];
        }
    }
    sscanf(buf, "%d", &res);
    return res;
}


void increment_bits(short * bits, size_t count) 
{
    size_t k = count - 1;
    while(k >= 0) 
    {
        if(!bits[k])
        {
            bits[k] = 1;
            return;
        }
        else
        {
            bits[k] = 0;
        }
        --k;
    }
}


int multi_array_q4_sum(size_t count, int mtx[][count]) 
{
    int sum = 0, k = 0;
    for (size_t x = 0; x < count; ++x)
    {
        for (size_t y = 0; y < count; ++y)
        {
            if(x == k && y <= count - 1 - k && y >= k) 
            {
                sum += mtx[y][x];
                printf("%d\n", mtx[y][x]);
            }
        }
        ++k;
    }
    return sum;
}


int main(int argc, char const *argv[])
{
    FILE * input = fopen("test.csv", "r");
    if (input == NULL) {
        return 1;
    }

    char line [MAX_LINE] = {};

    while(fgets(line, MAX_LINE, input)) {
        printf("%s", line);
    }

    fclose(input);
}
