#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

double* full_elements(double *ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        ptr_array[i] = (double)rand() / RAND_MAX * 2 - 1; // Значения от -1 до 1
    }
    return ptr_array;
}

int delete_k(double* ptr_arr, int size, int k) {
    for (int i = k; i < (size - 1); i++) {
        ptr_arr[i] = ptr_arr[i + 1];
    }
    return size - 1; 
}

int insert_after_k(double** ptr_arr, int size, int k, double value) {
    double* new_arr = (double*)malloc((size + 1) * sizeof(double));
    if (new_arr == NULL) {
        puts("Ошибка выделения памяти");
        return size;
    }

    for (int i = 0; i <= k; i++) {
        new_arr[i] = (*ptr_arr)[i];
    }
    new_arr[k + 1] = value;
    for (int i = k + 1; i < size; i++) {
        new_arr[i + 1] = (*ptr_arr)[i];
    }

    free(*ptr_arr);
    *ptr_arr = new_arr;

    return size + 1; 
}

void put_elements(double *ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%.5lg ", ptr_array[i]);
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "RUS");
    double *ptr_array;
    int size, k;

    srand(time(NULL));

    printf("Введите размер массива: ");
    scanf("%d", &size);

    ptr_array = (double*)malloc(size * sizeof(double));
    if (ptr_array == NULL) {
        puts("Ошибка выделения памяти");
        return -1;
    }

    full_elements(ptr_array, size);
    printf("Исходный массив:\n");
    put_elements(ptr_array, size);

    printf("Введите индекс элемента для удаления: ");
    scanf("%d", &k);
    if (k >= 0 && k < size) {
        size = delete_k(ptr_array, size, k);
        printf("Массив после удаления элемента:\n");
        put_elements(ptr_array, size);
    } else {
        printf("Некорректный индекс для удаления.\n");
    }

    printf("Введите индекс элемента для вставки после него: ");
    scanf("%d", &k);
    if (k >= 0 && k < size) {
        size = insert_after_k(&ptr_array, size, k, -999);
        printf("Массив после вставки элемента:\n");
        put_elements(ptr_array, size);
    } else {
        printf("Некорректный индекс для вставки.\n");
    }

    free(ptr_array);
}
