#include <stdio.h>
#include <math.h>

void main () {
    const maximum_elements = 8;
    int result, arr[maximum_elements], i,  min_number, sum = 0, counter = 0;

    for (i = 0; i < maximum_elements; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
// Находим количество елементов массива равных 0:
    for(i = 0; i < maximum_elements; i++){
        if(arr[i] == 0){
            counter++;
        }
    }
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


    printf("Количество елементов массива равных 0: %.0d\n", counter );
    printf("Сумма элементов массива, расположенных после минимального элемента: %d\n", sum);
    printf("Отсортированный массив:\n");
    for (i = 0; i < maximum_elements; printf("%d ", arr[i++]));



    return;
}

    