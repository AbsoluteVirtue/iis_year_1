#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 80


int main(int argc, char const *argv[])
{
    // сохранение содержимого файла в памяти
    FILE * input = fopen("census.csv", "r");
    if (input == NULL) {
        return 1;
    }

    char line [MAX_LINE] = {};
    // построчное чтение содержимого файла из памяти в массив
    while(fgets(line, MAX_LINE, input)) {
        printf("%s", line);
    }

    // освобождение выделенной памяти
    fclose(input);

    return 0;
}
