#include <iso646.h>
#include <stdio.h>
#include <stdlib.h>


// структура, состоящая из примитивных типов
typedef struct _test
{
    int days;
    int months;
    int years;
    char * name;

} test_t;


// структура с внутренней структурой
typedef struct _supertest
{
    test_t ts;

} supertest_t;


// инициализация структуры по ссылке
void _test_init(test_t * source) {
    source->days = 1;
    source->months = 1;
    source->years = 1970;
    source->name = NULL;
}


int main(int argc, char const *argv[])
{
    // объявление структуры
    test_t T;

    _test_init(&T);

    // инициализация структуры буквально
    supertest_t time = {T};

    // доступ к элементу по значению
    time.ts.days += 1;

    return 0;
}
