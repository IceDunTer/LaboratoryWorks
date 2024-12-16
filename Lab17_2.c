#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int* full_array(int* ptrarr, int size) {
    for (int i = 0; i < size; i++) {
        ptrarr[i] = rand() % 100;
    }
    return ptrarr;
}

void put_array(int* ptrarr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", ptrarr[i]);
    }
    printf("\n");
}

void sort_insert(int* ptrarr, int size) {
    int key, j;
    for (int i = 1; i < size; i++) {
        key = ptrarr[i];
        j = i - 1;
        while (j >= 0 && ptrarr[j] > key) {
            ptrarr[j + 1] = ptrarr[j];
            j = j - 1;
        }
        ptrarr[j + 1] = key;
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));

    int size = 10;
    int arr[size];

    full_array(arr, size);
    printf("Исходный массив: ");
    put_array(arr, size);

    clock_t start = clock();
    sort_insert(arr, size);
    clock_t end = clock();

    printf("Отсортированный массив: ");
    put_array(arr, size);

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Время выполнения сортировки вставками: %f секунд\n", time_spent);
}
