#include <stdio.h>
#include <stdlib.h>

#define ARR_LEN 7
#define NO_OF_ROWS 3
#define ROW_LENGTH 4

// отсортировать элементы по модулю с помощью qsort
int _compare(const void *a, const void *b)
{
    return (abs(*(int *)a) - abs(*(int *)b));
}

int main(int argc, char const *argv[])
{
    int array_lit[ARR_LEN] = {0, -90, 0, 78, -13, -456, 0};
    // найти минимальный элемент, количество нулевых элементов, четные/нечетные числа в массиве
    int min = 0;
    int k = 0;
    for (int i = 0; i < ARR_LEN; ++i)
    {
        if (array_lit[i] < array_lit[min])
        {
            min = i;
        }

        if (!array_lit[i])
        {
            k += 1;
        }

        if (array_lit[i] % 2)
        {
            printf("%d is odd\n", array_lit[i]);
        }
        else
        {
            printf("%d is even\n", array_lit[i]);
        }
    }

    // найти сумму элементов начиная с индекса, хранящегося в переменной min
    int sum = 0;
    for (; min < ARR_LEN; printf("%d", min++))
    {
        sum += array_lit[min];
    }

    for (int i = 0; i < ARR_LEN; ++i)
    {
        for (int j = i + 1; j < ARR_LEN; ++j)
        {
            if (array_lit[i] > array_lit[j])
            {
                int tmp = array_lit[i];
                array_lit[i] = array_lit[j];
                array_lit[j] = tmp;
            }
        }
    }

    qsort(array_lit, 7, sizeof(*array_lit), _compare);

    // найти первую колонку, в которой есть нулевой элемент
    int array[NO_OF_ROWS][ROW_LENGTH] = {
        {1, 3, 8, 5},
        {3, 12, 0, 13},
        {4, 6, 8, 14},
    };

    for (int i = 0; i < ROW_LENGTH; ++i)
    {
        for (int j = 0; j < NO_OF_ROWS; ++j)
        {
            if (array[j][i] == 0)
            {
                printf("%d", j + 1);
            }
        }
    }

    return 0;
}
