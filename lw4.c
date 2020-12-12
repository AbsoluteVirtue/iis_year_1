#include <stdlib.h>
#include <stdio.h>

#define N 6

// структура, состоящая из примитивных типов
typedef struct _time
{
    int days;
    int months;
    int years;
    char *name;
} time;

// структура с внутренней структурой
typedef struct _record
{
    time ts;
} record;

void _date_init(time *source)
{
    // изменение полей структуры по ссылке
    source->days = 1;
    source->months = 1;
    source->years = 1970;
    source->name = NULL;
}

int main(int argc, char const *argv[])
{
    // выделение памяти под массив, все элементы обнуляются в случае успешной операции
    record *array = (record *)calloc(N, sizeof(record));
    if (array == NULL)
    {
        return -1;
    }

    for (int i = 0; i < N; ++i)
    {
        // инициализация структуры по ссылке
        time date;
        _date_init(&date);
        // изменения поля структуры по значению
        date.days += i;
        // инициализация структуры буквально
        record rec = {date};
        array[i] = rec;
    }

    for (int i = 0; i < N; ++i)
    {
        printf(
            "%d-%d-%d\n",
            array[i].ts.years,
            array[i].ts.months,
            array[i].ts.days);
    }

    // освобождение памяти, выделенной с помощью calloc
    free(array);

    return 0;
}
