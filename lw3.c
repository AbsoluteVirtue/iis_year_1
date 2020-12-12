#include <stdio.h>
#include <stdlib.h>

#define NO_OF_ROWS 3
#define ROW_LENGTH 4

int _compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(int argc, char const *argv[])
{
    // инициализация двумерного массива буквально
    int array[NO_OF_ROWS][ROW_LENGTH] = {
        {1, 3, 8, 5},
        {3, 12, 0, 13},
        {4, 6, 8, 14},
    };

    int array_index = 0, row_index = 1;

    // доступ к конкретному элементу по индексам ряда/элемента
    printf("Access by index: %d\n", array[array_index][row_index]);

    // доступ к конкретному элементу по указателю
    printf("Access by cast pointer: %d\n", *((int *)array + array_index * ROW_LENGTH + row_index));

    // вывод двумерного массива по индексам ряда/элемента
    for (int i = 0; i < NO_OF_ROWS; ++i)
    {
        for (int j = 0; j < ROW_LENGTH; ++j)
        {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }

    // размеры массива в памяти: целиком, одного ряда (внутреннего массива), одного элемента ряда - в байтах
    size_t total_size = sizeof(array);
    size_t row_size = sizeof(*array);
    size_t item_size = sizeof(*(int *)array);
    size_t array_total_items = (total_size / item_size);

    // максимальное из чисел, встречающихся в массиве более одного раза
    qsort(array, array_total_items, item_size, _compare);

    int max_repeated_item = 0;
    for (
        int *p = (int *)array + 1;
        p < (int *)array + array_total_items;
        ++p)
    {

        if (*p == *(p - 1))
            max_repeated_item = *p;
    }
    printf("Max item that repeats at least once: %d\n", max_repeated_item);

    // количество строк, не содержащих ни одного нулевого элемента
    int counter = 0;
    for (int i = 0; i < NO_OF_ROWS; ++i)
    {
        int flag = 1;
        for (int j = 0; j < ROW_LENGTH; ++j)
        {
            if (!array[i][j])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            counter++;
    }
    printf("Number or rows w/o 0: %d", counter);

    return 0;
}
