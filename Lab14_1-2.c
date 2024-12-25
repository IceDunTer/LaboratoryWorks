#include <stdio.h>
#include <locale.h>
#include <math.h>
#define N 1000

void full_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] = pow(i, 2) - 4 * i + 2;
    }
}

double sum_elems(double* ptr_array, int s, int e) {
    double summ = 0;
    for (int i = s; i <= e; i++) {
        summ += ptr_array[i];
    }
    return summ;
}

int find_elem(double* ptr_array, int n, double elem) {
    for (int i = 0; i < n; i++) {
        if (fabs(ptr_array[i] - elem) < 1e-9) {
            return i;
        }
    }
    return -1;
}

void put_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        printf("a[%i] = %lg\n", i, ptr_array[i]);
    }
}

void calc_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] = ptr_array[i] * 2;
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    double array[N];
    int size, start, end;
    double num;

    puts("Введите размер массива (< 1000):");
    scanf("%i", &size);
    full_elements(array, size);
    put_elements(array, size);

    puts("Введите начальный индекс:");
    scanf("%i", &start);
    puts("Введите конечный индекс:");
    scanf("%i", &end);
    puts("Введите число для поиска в массиве:");
    scanf("%lg", &num);

    printf("\n%lg\n", sum_elems(array, start, end));
    int index = find_elem(array, size, num);
    if (index != -1) {
        printf("Номер ближайшего индекса для числа %lg - %i\n", num, index);
    }
    else {
        printf("Элемент %lg не найден в массиве.\n", num);
    }
}
