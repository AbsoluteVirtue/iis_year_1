#include <math.h>

#define ARR_LENGTH 7


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

    // копирование N символов из одной строки в другую

    // простая реализация, количество копируемых символов не может превышать длину принимающей строки 
    char dest1 [ARR_LENGTH] = {};

    strncpy_simple(dest1, "hello", 4);

    char dest2 [ARR_LENGTH] = {};

    strncpy_smart(dest2, "world", 4);

    return;

}
