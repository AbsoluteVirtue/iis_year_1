#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 80


void _strncpy(char * dest, const char * src, size_t count)
{
    size_t len = (count > strlen(src)) ? strlen(src) : count;
    for (size_t i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
    dest[len] = '\0';
}


int _strncmp(const char * lhs, const char * rhs, size_t count)
{
    size_t len = (strlen(rhs) > strlen(lhs)) ? strlen(lhs) : strlen(rhs);
    size_t k = (count > len) ? len : count;
    for (size_t i = 0; i < k; i++)
    {
        if (lhs[i] != rhs[i]) 
        {
            return lhs[i] - rhs[i];
        }
    }
    return 0;
}


int _atoi(const char * src) 
{
    int res = 0;
    char buf [80] = {};
    size_t i = 0, k = 0;
    while (src[i])
    {
        if(isdigit(src[i])) {
            buf[k++] = src[i];
        }
        ++i;
    }
    sscanf(buf, "%i", &res);
    return res;
}


void bytewise_inc(unsigned short * src, size_t count) 
{
    for (size_t i = count - 1; i >= 0; i--)
    {
        if (src[i]) 
        {
            src[i] = 0;
        } else {
            src[i] = 1;
            return;
        }
    }
}


int main(int argc, char const *argv[])
{
    // " -123junk"  -123
    // "junk"       0
    // "-junk123"   123
    const char * test = "Happy New Year 2021!";
    int r = _atoi(test);
    printf("%d", r);

    // 128 64 32 16 8 4 2 1

    //   7  6  5  4 3 2 1 0

    //   1  0  1  0 1 1 1 1     175
    //   0  0  0  1 0 1 0 0     20

    unsigned short b [] = {0, 0,0, 1, 0, 0,1,1};

    bytewise_inc(b, 8);
    for (size_t i = 0; i < 8; i++)
    {
       printf("%i", b[i]);
    }

    printf("\n");

    int m [N][N] = {
        {1, 2, 3, 4, 9},
        {5, 6, 7, 8, 1},
        {1, 2, 3, 4, 8},
        {5, 6, 7, 8, 0},
        {5, 6, 7, 8, 1},
    };

    /*
        \ 1 /
         \ /
        4/ \2
        / 3 \
    */

    int sum = 0;
    for (size_t i = 0; i < (N / 2) + 1; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            if (j <= N - 1 - i && j >= i) 
            {
                sum += m[j][i];
                printf("%d", m[j][i]);
            }
        }
    }

    printf("\n%d", sum);
}
