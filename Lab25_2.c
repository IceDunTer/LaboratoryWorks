#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int rand10(int mmin, int mmax) {
    return mmin + rand() % (mmax - mmin + 1);
}

double rand_double(double dmin, double dmax) {
    return dmin + (double)rand() / RAND_MAX * (dmax - dmin);
}

int* rand10n(int n, int mmin, int mmax) {
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        perror("Ошибка выделения памяти");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = rand10(mmin, mmax);
    }
    return arr;
}

double* rand_double_n(int n, double dmin, double dmax) {
    double* arr = (double*)malloc(n * sizeof(double));
    if (arr == NULL) {
        perror("Ошибка выделения памяти");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = rand_double(dmin, dmax);
    }
    return arr;
}

void print_int_array(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void print_double_array(double* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int mmin = 1, mmax = 10;
    double dmin = 1.0, dmax = 10.0;
    int n = 5;

    int rand_int = rand10(mmin, mmax);
    printf("Случайное целое число: %i\n", rand_int);

    double rand_double_val = rand_double(dmin, dmax);
    printf("Случайное число с плавающей точкой: %.2lg\n", rand_double_val);

    int* rand_int_arr = rand10n(n, mmin, mmax);
    printf("Массив случайных целых чисел: ");
    print_int_array(rand_int_arr, n);
    free(rand_int_arr);

    double* rand_double_arr = rand_double_n(n, dmin, dmax);
    printf("Массив случайных чисел с плавающей точкой: ");
    print_double_array(rand_double_arr, n);
    free(rand_double_arr);
}
