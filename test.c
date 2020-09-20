#include <stdio.h>
#include <string.h>


typedef struct _type {
    int _i;
    char * _c;

} t;


int fibonacci(int number_of_items) {

    int array [20] = {};
    array[1] = 1;
    for (int i = 2; i <= number_of_items; ++i) {
        array[i] = array[i - 1] + array[i - 2];
    }
    return array[number_of_items];
}

void main(int argc, char const *argv[])
{

    int res = fibonacci(20);

    return;
}
