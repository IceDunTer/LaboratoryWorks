#include <stdio.h>
#include <locale.h>

void sort_bubble(int* ptrarr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ptrarr[j] > ptrarr[j + 1]) {
                int temp = ptrarr[j];
                ptrarr[j] = ptrarr[j + 1];
                ptrarr[j + 1] = temp;
            }
        }
    }
}

void sort_shaker(int* ptrarr, int n) {
    int left = 0;
    int right = n - 1;
    while (left < right) {
        for (int i = left; i < right; i++) {
            if (ptrarr[i] > ptrarr[i + 1]) {
                int temp = ptrarr[i];
                ptrarr[i] = ptrarr[i + 1];
                ptrarr[i + 1] = temp;
            }
        }
        right--;

        for (int i = right; i > left; i--) {
            if (ptrarr[i - 1] > ptrarr[i]) {
                int temp = ptrarr[i];
                ptrarr[i] = ptrarr[i - 1];
                ptrarr[i - 1] = temp;
            }
        }
        left++;
    }
}

void sort_select(int* ptrarr, int n) {
    int temp, min_idx;
    for (int i = 0; i < n - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (ptrarr[j] < ptrarr[min_idx]) {
                min_idx = j;
            }
        }
        temp = ptrarr[min_idx];
        ptrarr[min_idx] = ptrarr[i];
        ptrarr[i] = temp;
    }
}

void sort_insert(int* ptrarr, int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
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
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Исходный массив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    sort_bubble(arr, n);
    printf("Пузырьковая сортировка: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int arr_shaker[] = {64, 34, 25, 12, 22, 11, 90};
    sort_shaker(arr_shaker, n);
    printf("Шейкерная сортировка: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr_shaker[i]);
    }
    printf("\n");

    int arr_select[] = {64, 34, 25, 12, 22, 11, 90};
    sort_select(arr_select, n);
    printf("Сортировка простым выбором: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr_select[i]);
    }
    printf("\n");

    int arr_insert[] = {64, 34, 25, 12, 22, 11, 90};
    sort_insert(arr_insert, n);
    printf("Сортировка вставками: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr_insert[i]);
    }
    printf("\n");
}
