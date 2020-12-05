#include <math.h>
#include <stdio.h>

#ifndef INT_MAX
#define INT_MAX 99999
#endif

#define ARR_LENGTH 7
#define true 1
#define false 0

void strncpy_smart(char *dest, const char *src, int n)
{
    do
    {
        if (!n--)
            return;

    } while (*dest++ = *src++);

    while (n--)
        *dest++ = 0;

    return;
}

void main(int argc, char const *argv[])
{
    // найти длину самой длинной цепочки повторяющихся элементов, идущих подряд
    int arr_chain[ARR_LENGTH] = {6, 6, 6, 8, 2, 2, 0};
    unsigned int counter = 1, max = 1;
    for (int i = 1; i < ARR_LENGTH; ++i)
    {
        if (arr_chain[i] == arr_chain[i - 1])
        {
            ++counter;
        }
        else
        {
            counter = 1;
        }
        if (max < counter)
            max = counter;
    }
    printf("%d\n", counter);

    // найти минимальную четную цифру произвольного числа
    unsigned int number = 123478, min = number, remainder = 0;
    while (number)
    {
        remainder = number % 10;
        if (!(remainder % 2) && remainder < min)
        {
            min = remainder;
        }
        number /= 10;
    }
    printf("%d\n", min);

    // вывод равнобедренного треугольника на экран
    int i = 0;
    for (; i < ARR_LENGTH; i += 1)
    {
        for (int j = 0; j < (ARR_LENGTH - i - 1); ++j)
        {
            printf(" ");
        }
        printf("+");
        for (int k = 0; k < i; k += 1)
        {
            printf("-+");
        }
        printf("\n");
    }

    // проверка числа на простоту, число должно быть больше 2
    int prime_number = 43, is_prime = true;
    for (int i = 2; i * i < prime_number; i += 1)
    {
        if (!(prime_number % i))
        {
            is_prime = false;
            printf("is not prime");
            break;
        }
    }
    if (is_prime)
        printf("is prime");

    // Найти N-е число ряда Фибоначчи
    unsigned int fib_array[ARR_LENGTH] = {};
    fib_array[0] = 0;
    fib_array[1] = 1;
    for (int i = 2; i <= ARR_LENGTH; i += 1)
    {
        fib_array[i] = fib_array[i - 1] + fib_array[i - 2];
    }
    printf("%d", fib_array[ARR_LENGTH]);

    // копирование N символов из одной строки в другую
    // реализация копирования с указателями
    char dest2[ARR_LENGTH] = {};
    strncpy_smart(dest2, "world", 4);
    printf("%s", dest2);

    // слияние двух массивов в третий массив за один проход
    int A[ARR_LENGTH] = {0, -2, 4, 0, -4, 3, -5};
    int B[ARR_LENGTH] = {3, -4, 5, 7, 1, -2, 4};
    int R[ARR_LENGTH + ARR_LENGTH] = {};
    int min = INT_MAX;
    for (int j = 0; j < ARR_LENGTH + ARR_LENGTH; j++)
    {
        int i = 0, k = 0;
        min = INT_MAX;
        int flag = -1;
        for (; i < ARR_LENGTH; i++)
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
}
