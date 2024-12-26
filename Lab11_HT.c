#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

#define n 10

// Контрольный пример 1: [1, 3, 4, -2, 5, 6, 7, 8, 9, -24] - 8
// Контрольный пример 2: [5, 11, 3, 4, 1, 2, -6, 2, -4, 2] - 26

int main() {
    setlocale(LC_ALL, "RUS");
    int arr[n];
    int lastPositiveIndex = -1;

    printf("Введите элементы массива:\n");
    for (int i = 0; i < n; i++) {
        scanf("%i", &arr[i]);
        if (arr[i] > 0) {
            lastPositiveIndex = i;
        }
    }

    if (lastPositiveIndex == -1) {
        printf("В массиве нет положительных элементов.\n");
        return 1;
    }

    int sum = 0;
    for (int i = 0; i < lastPositiveIndex; i++) {
        sum += arr[i];
    }
    printf("Сумма всех элементов, расположенных до последнего положительного элемента: %i\n", sum);
}
