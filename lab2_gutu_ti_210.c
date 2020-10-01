#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define maximum_elements 8

void main () {
    int result, arr[maximum_elements] = {1, -2, 13, 4, -5, 66, 7, 0}; 
    int i,  min_number, sum = 0, counter = 0;

// Находим количество елементов массива равных 0:
    for(i = 0; i < maximum_elements; i++){
        if(arr[i] == 0){
            counter++;
        }
    }
    printf("Количество елементов массива равных 0: %.0d\n", counter );

// Находим минимальный элемент массива:
    int min = arr[0];
    for(i = 0; i < maximum_elements; i++){
        if(min > arr[i]){
            min = arr[i];
        }
    }
// Находим номер минимальноно элемента массива:
    for(i = 0; i < maximum_elements; i++){
        if(min == arr[i]){
            min_number = i;
            break;
        }
    }
// Находим сумму элементов массива, расположенных после минимального элемента:
    for(i = min_number + 1; i < maximum_elements; i++){
        sum+= arr[i];
    }
    printf("Сумма элементов массива, расположенных после минимального элемента: %d\n", sum);


// Сортируем массив по заданию:
    for (i = 0; i < maximum_elements; i++)
    {
        for (int j = i + 1; j < maximum_elements; j++)
        {
            if (abs(arr[i]) > abs(arr[j]))
            {
                result = arr[i];
                arr[i] = arr[j];
                arr[j] = result;
            }
        }
    }

    printf("Отсортированный массив:\n");
    for (i = 0; i < maximum_elements; printf("%d ", arr[i++]));



    return;
}

    