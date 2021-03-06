#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <iso646.h>

#define ARRAY_LENGTH 8

int has_str(char *src_str, char *cmp_str)
{
    char *items[80] = {};

    char *tmp_str = (char *)malloc(strlen(src_str) + 1);
    strcpy(tmp_str, src_str);

    char *token = strtok(tmp_str, ",");
    int i = 0;
    while (token != NULL)
    {
        items[i++] = token;
        token = strtok(NULL, ",");
    }

    free(tmp_str);

    char *fmt_str;
    sprintf(fmt_str, "%s,%s", items[0], items[1]);

    if (!strcmp(fmt_str, cmp_str))
    {
        return 1;
    }

    return 0;
}

int _get_random_range(int lower, int upper)
{
    return lower + (rand() % (upper - lower));
}

void input()
{
    char line[256];
    int i;
    if (fgets(line, sizeof(line), stdin))
    {
        if (1 != sscanf(line, "%d", &i))
        {
            printf("input error!");
            return;
        }
    }
}

void print_array_string(char _a[])
{
    int size = strlen(_a);
    char *ap = (char *)malloc(size + 1);
    for (int j = 0; j < size; j += 1)
    {
        ap[j] = _a[j];
    }
    ap[size] = '\0';
    for (int i = 0; i < size + 1; i += 1)
    {
        printf("%c\t", ap[i]);
    }
    free(ap);
}

void array_allocation(int size)
{
    char *pa = (char *)malloc(size + 1);
    if (pa != NULL)
    {
        for (int i = 0; i < size; i += 1)
        {
            char ch;
            if (scanf("%c", &ch) == 1)
            {
                pa[i] = ch;
            }
        }
        pa[size] = '\0';
        printf("%s", pa);
    }
    free(pa);
}

void strcopy(char *p, char *new, int N)
{
    for (int i = 0; i <= N; i += 1)
    {
        if (!p[i])
            break;

        new[i] = p[i];
    }
    new[N] = '\0';
}

void single_pass_min_2(int *arr, int size)
{
    int tmp_0 = arr[0];
    int tmp_1 = arr[1];

    for (int i = 2; i < size; ++i)
    {
        if (arr[i] < tmp_0)
        {
            if (tmp_1 > tmp_0)
            {
                tmp_1 = tmp_0;
            }
            tmp_0 = arr[i];
        }
        else if (arr[i] < tmp_1 && arr[i] != tmp_0)
        {
            tmp_1 = arr[i];
        }
    }
}

int fibonacci(int n)
{
    int array[n];
    array[0] = 0;
    array[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        array[i] = array[i - 1] + array[i - 2];
    }
    return array[n];
}

void two_dim_array_single_pass(int array[][4], int N, int M)
{
    for (int *p = (int *)array; p < (int *)array + (N * M); ++p)
    {
        printf("%d\n", *p);
    }
}

int *merge_arrays(int *A, int *B, size_t N, size_t M)
{
    int a = N - 1, b = 0;
    int *C = (int *)calloc(N + M, sizeof(int));

    for (int i = 0; i < N + N; ++i)
    {
        if (B[b] >= A[a])
        {
            C[i] = B[b++];
        }
        else if (B[b] <= A[a])
        {
            C[i] = A[a--];
        }
    }
    return C;
}

void printn(char c, int n)
{
    while (--n >= 0)
    {
        putchar(c);
    }
}

void reverse(int *head, int *tail)
{
    if (head < tail)
    {
        *head = *head + *tail;
        *tail = *head - *tail;
        *head = *head - *tail;
        reverse(head + 1, tail - 1);
    }
}

char *Reverse(char text[])
{
    char *begin = text;
    char *end = text + strlen(text) - 1;
    char tmp;

    for (; begin < end; ++begin, --end)
    {
        tmp = *begin;
        *begin = *end;
        *end = tmp;
    }

    return text;
}

int main(int argc, char const *argv[])
{
    int A[ARRAY_LENGTH] = {0, -2, 4, 0, -4, 3, -5, 1};
    int B[ARRAY_LENGTH] = {3, -4, 5, 7, 1, -2, 4, 0};
    int R[ARRAY_LENGTH * 2] = {};
    int min = INT_MAX;
    for (int j = 0; j < ARRAY_LENGTH * 2; j++)
    {
        int i = 0, k = 0;
        min = INT_MAX;
        int flag = -1;
        for (; i < ARRAY_LENGTH; i++)
        {
            if (A[i] < min)
            {
                min = A[i];
                k = i;
                flag = 1;
            }
            else if (B[i] < min)
            {
                min = B[i];
                k = i;
                flag = 0;
            }
        }
        if (flag != -1)
        {
            if (flag)
            {
                A[k] = INT_MAX;
            }
            else
            {
                B[k] = INT_MAX;
            }
        }
        R[j] = min;
    }

    return 0;
}
