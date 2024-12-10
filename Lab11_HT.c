#include <stdio.h>
#include <math.h>
#include <locale.h>
#define N 10

// Контрольный пример 1: [1, 3, 4, -2, 5, 6, 7, 8, 9, -24] - 8
// Контрольный пример 2: [5, 11, 3, 4, 1, 2, -6, 2, -4, 2] - 26

int main() {
    setlocale(LC_ALL, "RUS");
    double arr[N], a;
    double summary = 0;
    puts("Введите 10 чисел для заполнения массива:");
    for (int i = 0; i < N; i++) {  
        scanf_s("%lg", &a);
        arr[i] = a;
    }
    for (int i = 0; i < N; i++) {
        if (arr[i] >= 0) {
            summary += arr[i];
        }
        else {
            printf("Сумма всех элементов массива до последнего положительного элемента: %lg", summary);
            break;
        }
    }

}