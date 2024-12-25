#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

double* full_elements(double* ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        ptr_array[i] = (double)rand() / RAND_MAX * 2 - 1; // Значения от -1 до 1
    }
    return ptr_array;
}

int delete_k_elements(double* ptr_arr, int size, int start_index, int k) {
    for (int i = start_index; i < (size - k); i++) {
        ptr_arr[i] = ptr_arr[i + k];
    }
    return size - k;
}

int insert_after_k(double** ptr_arr, int size, int index, int k, double value) {
    double* new_arr = (double*)malloc((size + k) * sizeof(double));
    if (new_arr == NULL) {
        puts("Ошибка выделения памяти");
        return size;
    }

    // Копируем элементы до индекса index
    for (int i = 0; i <= index; i++) {
        new_arr[i] = (*ptr_arr)[i];
    }

    // Вставляем значение value k раз
    for (int j = 0; j < k; j++) {
        new_arr[index + 1 + j] = value;
    }

    // Копируем оставшиеся элементы
    for (int i = index + 1, j = index + 1 + k; i < size; i++, j++) {
        new_arr[j] = (*ptr_arr)[i];
    }

    free(*ptr_arr);
    *ptr_arr = new_arr;

    return size + k;
}

int find_min_index(double* ptr_array, int size) {
    int min_index = 0;
    double min_value = ptr_array[0];
    for (int i = 1; i < size; i++) {
        if (ptr_array[i] < min_value) {
            min_value = ptr_array[i];
            min_index = i;
        }
    }
    return min_index;
}

void put_elements(double* ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%.5lg ", ptr_array[i]);
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "RUS");
    double* ptr_array;
    int size, start_index, k;
    srand(time(NULL));

    printf("Введите размер массива: ");
    scanf("%i", &size);

    ptr_array = (double*)malloc(size * sizeof(double));
    if (ptr_array == NULL) {
        puts("Ошибка выделения памяти");
        return -1;
    }

    full_elements(ptr_array, size);
    printf("Исходный массив:\n");
    put_elements(ptr_array, size);

    printf("Введите начальный индекс для удаления K элементов: ");
    scanf("%i", &start_index);
    printf("Введите количество элементов для удаления: ");
    scanf("%i", &k);
    if (start_index >= 0 && start_index < size && k > 0 && start_index + k <= size) {
        size = delete_k_elements(ptr_array, size, start_index, k);
        printf("Массив после удаления элементов:\n");
        put_elements(ptr_array, size);
    }
    else {
        printf("Некорректные индекс или количество элементов для удаления.\n");
    }

    int min_index = find_min_index(ptr_array, size);
    printf("Индекс минимального элемента: %d\n", min_index);

    printf("Введите количество элементов для вставки после минимального элемента: ");
    scanf("%i", &k);
    if (min_index >= 0 && min_index < size && k > 0) {
        size = insert_after_k(&ptr_array, size, min_index, k, -999);
        printf("Массив после вставки элементов:\n");
        put_elements(ptr_array, size);
    }
    else {
        printf("Некорректные индекс или количество элементов для вставки.\n");
    }

    free(ptr_array);
    return 0;
}
