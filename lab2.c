#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_LEN 7


int _get_random_range(int lower, int upper) {

    return lower + ( rand() % (upper - lower) );
}


void _print_array(int _a [], int size) {

    for (int i = 0; i < size; ++i) {
        printf("%d\t", _a[i]);
    }
}


int _compare(const void * a, const void * b) {

    return ( *(int*)a - *(int*)b );
}


void main(int argc, char const *argv[])
{
    // инициализация массива данными пользователя через список аргументов argv
    int array_arg [ARR_LEN] = {};

    for (int i = 0; i < ARR_LEN; ++i) {
        array_arg[i] = (int)atoi(argv[i + 1]);
    }

    // инициализация массива псевдо-случайными значениями в заданном диапазоне
    int array_rand [ARR_LEN] = {};

    // инициализация ряда псевдо-случайных чисел текущим временем системы
    srand( time(0) );

    for (int i = 0; i < ARR_LEN; ++i) {
        array_rand[i] = _get_random_range(-100, 100);
    }

    // инициализация массива числами из ряда Фибоначчи
    int array_fib [ARR_LEN] = {};

    for (int i = 0; i < ARR_LEN; ++i) {
        if (i < 2) {
            array_fib[i] = i;
            continue;
        }
        array_fib[i] = array_fib[i - 1] + array_fib[i - 2];
    } 

    // инициализация массива буквально
    int array_lit [] = {67, -90, 45, 78, -13, -456, 4};


    // пример фильтрации элементов массива (чет-нечет)
    for (int i = 0; i < ARR_LEN; ++i) {
        if (array_lit[i] % 2) {
            printf("%d is odd\n", array_lit[i]);
        } else {
            printf("%d is even\n", array_lit[i]);
        }
    } 


    // быстрая сортировка массива (см. ф-цию сравнения выше)
    qsort(array_lit, ARR_LEN, sizeof(*array_lit), _compare);

    printf("Sorted array:\t");

    _print_array(array_lit, ARR_LEN);

    return;
}
