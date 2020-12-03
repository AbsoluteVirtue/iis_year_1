#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5


char * _strncpy(char * dest, const char * src, size_t count)
{
    size_t len = (count > strlen(src)) ? strlen(src) : count;
    for (size_t i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
    dest[len] = '\0';
    return dest;
}


int _strncmp(const char * lhs, const char * rhs, size_t count)
{
    // TODO: строки отличаются, если они разной длины, и count больше обеих
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


int _atoi(const char * str) 
{
    // TODO: добавить определение отрицательных чисел
    int res = 0;
    char buf [strlen(str)];
    size_t i = 0, k = 0, stop = 0;
    while (str[i])
    {
        stop = k;
        if (isdigit(str[i]))
            buf[k++] = str[i];
        if (k && stop == k)
            break;
        ++i;
    }
    if (k) 
    {
        buf[k] = '\0';
        sscanf(buf, "%i", &res);
    }
    return res;
}


void bytewise_inc(unsigned short * src, size_t count) 
{
    for (size_t i = count - 1; i >= 0; i--)
    {
        if (src[i])
        {
            src[i] = 0;
        } 
        else
        {
            src[i] = 1;
            return;
        }
    }
}


int main(int argc, char const *argv[])
{
    const char * s1 = "Happy New Year 2021!";
    char * s2 = (char *)malloc(strlen(s1) + 1);
    _strncpy(s2, s1, 19);
    printf("Copied string: %s\n", s2);

    ////////////////////////////////

    printf("Comparison result: %d\n", _strncmp(s1, s2, 27));

    ////////////////////////////////

    /*
        конвертирование строк в числа

                        ожидаемый
        ввод:           результат:
        " -123junk"     -123
        "junk"          0
        "-junk123"      123
    */
    const char * val = "-312junk123";
    printf("Converted value from %s: %d\n", val, _atoi(val));

    ////////////////////////////////

    /*
        десятичное представление двоичных чисел

          7  6  5  4 3 2 1 0    (степень 2-ки)
        128 64 32 16 8 4 2 1    (десятичное представление степени двойки в бите)

        1  0  1  0 1 1 1 1      175 (десятичная сумма битов, выставленных в 1)
        0  0  0  1 0 1 0 0      20
    */
    printf("Incremented value: ");

    unsigned short b [] = {0, 0, 0, 1, 0, 0, 1, 1};
    bytewise_inc(b, 8);
    for (size_t i = 0; i < 8; i++)
    {
       printf("%i", b[i]);
    }

    printf("\n");

    ////////////////////////////////

    /*
        четверти квадратной матрицы, включая диагонали

        \ 1 /
         \ /
       4 / \ 2
        / 3 \

        для четвертой четверти:
    */
    int m [N][N] = {
        {1, 2, 3, 4, 9},
        {5, 6, 7, 8, 1},
        {1, 2, 3, 4, 8},
        {5, 6, 7, 8, 0},
        {5, 6, 7, 8, 1},
    }, sum = 0;

    for (size_t i = 0; i < (N / 2) + 1; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            if (j <= N - 1 - i && j >= i) 
            {
                sum += m[j][i];
            }
        }
    }
    printf("Sum for given quarter: %d\n", sum);

    return 0;
}
