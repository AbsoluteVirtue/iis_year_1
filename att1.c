#include <math.h>
#include <stdio.h>

#define ARR_LENGTH 7
#define true 1
#define false 0


void strncpy_simple(char *dest, const char *src, int n) {

    for (int i = 0;i < n; ++i) {
        dest[i] = src[i];
        if (src[i] == '\0') {
            return;
        }
    }
    dest[n] = '\0';
}


void strncpy_smart(char *dest, const char *src, int n)
{
    do {
        if (!n--)
            return;
    } while (*dest++ = *src++);

    while (n--)
        *dest++ = 0;
    return;
}



void main(int argc, char const *argv[]) {

    // найти длину самой длинной цепочки повторяющихся элементов, идущих подряд
    int arr_chain [ARR_LENGTH] = {6, 6, 6, 8, 2, 2, 0};
    unsigned int counter = 1, max = 1;
    for(int i = 1; i < ARR_LENGTH; ++i) {
        if (arr_chain[i] == arr_chain[i - 1]) {
            ++counter;
        } else {
            if (max < counter) max = counter;

            counter = 1;
        }
    }
    printf("%d\n", counter);


    // найти минимальную четную цифру произвольного числа
    unsigned int number = 123478, min = number, remainder = 0;
    while(number) {
        remainder = number % 10;
        if (!(remainder % 2) && remainder < min) {
            min = remainder;
        }
        number /= 10;
    }
    printf("%d\n", min);


    // вывод равнобедренного треугольника на экран
    int i = 0;
    for (; i < ARR_LENGTH; i += 1) {
        for (int j = 0; j < (ARR_LENGTH - i - 1); ++j) {
            printf(" ");
        }
        printf("+");
        for (int k = 0; k < i; k += 1) {
            printf("-+");
        }
        printf("\n");
    }


    // проверка числа на простоту, число должно быть больше 2
    int prime_number = 43, is_prime = true;
    for (int i = 2; i*i < prime_number; i += 1) {
        if (!(prime_number % i)) {
            is_prime = false;
            printf("is not prime");
            break;
        }
    }
    if (is_prime) printf("is prime");


    // Найти N-е число ряда Фибоначчи
    unsigned int fib_array [ARR_LENGTH] = {};
    fib_array[0] = 0;
    fib_array[1] = 1;
    for (int i = 2; i <= ARR_LENGTH; i += 1) {
        fib_array[i] = fib_array[i - 1] + fib_array[i - 2];
    }
    printf("%d", fib_array[ARR_LENGTH]);


    // копирование N символов из одной строки в другую
    // простая реализация, количество копируемых символов не может превышать длину принимающей строки 
    char dest1 [ARR_LENGTH] = {};
    strncpy_simple(dest1, "hello", 7);
    printf("%s", dest1);

    // реализация с указателями 
    char dest2 [ARR_LENGTH] = {};
    strncpy_smart(dest2, "world", 4);
    printf("%s", dest2);

    return;
}
