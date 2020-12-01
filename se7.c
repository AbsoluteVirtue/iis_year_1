#include <iso646.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>


#define N 2

// объявление структуры
typedef struct sem
{
    char * flight_number;
    int flight_capacity;
} aero;


int main(int argc, char const *argv[])
{
    // сидирование генератора псевдо-случайных чисел текущим временем
    rands(time(0));
    // создание массива для хранения адресов строк из объектов типа aero
    aero ** A = (aero **)malloc(N * sizeof(aero *));
    
    for (int i = 0; i < N; ++i)
    {
        // создание одной строки из объектов типа aero и сохранение ее адреса в массиве А
        A[i] = (aero *)malloc(N * sizeof(aero));

        for (int j = 0; j < N; j++)
        {
            // сохранение значения поле объекта типа aero
            A[i][j].flight_capacity = rand() % 100;

            // обнуление буфера для ввода с клавиатуры
            char buf_num [80] = {};
            scanf("%s", buf_num);

            // расчет длины строки, введенной с клавиатуры
            size_t M = strlen(buf_num) + 1;

            // создание пустой строки символов для сохранения ввода с клавиатуры
            A[i][j].flight_number = (char *)malloc(M);

            // копирование строк
            strcpy(A[i][j].flight_number, buf_num);

            printf("%s %d\t", A[i][j].flight_number, A[i][j].flight_capacity);
        }
        printf("\n");
    }

    char search_term [80] = {};
    scanf("%s", search_term);

    // тип bool из библиотеки stdbool
    bool is_found = false;

    // ключевые слова and/not из библиотеки iso646
    for (int i = 0; i < N and not is_found; ++i)
    {
        for (int j = 0; j < N; j++)
        {
            // сравнение двух строк символов, если результат равен 0 - строки совпадают
            if (strcmp(A[i][j].flight_number, search_term) == 0)
            {
                printf("Flight #%s found (%d)\n", A[i][j].flight_number, A[i][j].flight_capacity);
                is_found = true;
                break;
            }
        }
    }

    // освобождение памяти в порядке, обратном порядку выделения
    // (чтобы не потерять доступ к участкам памяти, выделенным последними)
    for (int i = 0; i < N; ++i)
    {
        // освобождение памяти каждого текстового поля из объекта
        free(A[i]->flight_number);
        // освобождение памяти каждой строки массива
        free(A[i]);
    }
    // освобождение памяти первоначального массива
    free(A);

    return 0;
}
