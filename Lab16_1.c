#include <stdio.h>
#include <stdlib.h>

double* full_elements(double *ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        ptr_array[i] = (double)rand() / RAND_MAX * 20 - 10;
    }
    return ptr_array;
}

double* calc_elements(double *ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        ptr_array[i] *= 2; 
    }
    return ptr_array;
}

void put_elements(double *ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%.5lg ", ptr_array[i]);
    }
    printf("\n");
}

int main() {
    double *ptr_array;
    int size;

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

    double *new_array = (double*)malloc(size * sizeof(double));
    if (new_array == NULL) {
        puts("Ошибка выделения памяти");
        free(ptr_array);
        return -1;
    }
    for (int i = 0; i < size; i++) {
        new_array[i] = ptr_array[i];
    }

    calc_elements(new_array, size);
    printf("Преобразованный массив:\n");
    put_elements(new_array, size);

    free(ptr_array);
    free(new_array);
}