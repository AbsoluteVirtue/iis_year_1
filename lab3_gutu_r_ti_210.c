#include <stdio.h>
#include <stdlib.h>

#define n 3
#define m 3

int main(){

// Упорядочить строки массива по возрастанию количества положительных элементов в каждой строке.

// Задаем матрицу и другие переменные.
    int matrixx[n][m] = {
        {1, -2, -3},
        {-4, -5, -6}, 
        { 7, 8, -9} 
    }, array[n], count = 0, k;

// Выводим матрицу.
    printf("\n Ваша матрица : \n");
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m; j++){
            printf("%d \t", matrixx[i][j]);
        }
        printf("\n");
    }; 

// Считаем количество положительных элементов в каждой строке матрицы и записываем в новый одномерный массив.
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m; j++){
            if(matrixx[i][j] > 0){
               count++;
            }
        };
        array[i] = count;
        count = 0;
    };   
// По определенному алоритиму через 2 цикла for и if сортируем строки матрицы по возрастанию полож. элементов
// методом пузырька
  for(int i = 0;i < (n - 1);i++){
        for(int j = (m - 1);j >=0; j--){
            if(array[i] > array[i+1]){
                k=matrixx[i][j];
                matrixx[i][j]=matrixx[i+1][j];
                matrixx[i+1][j]=k;
            }
        }
    }

// Выводим полученную матрицу
    printf("\n Итоговая матрица : \n");
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m; j++){
            printf("%d \t", matrixx[i][j]);
        }
        printf("\n");
    };  
    
    return 0;
}