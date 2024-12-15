#include <stdio.h>
#include <locale.h>
#include <math.h>
#define Pi 3.1415926535

int lpi(double *ptr_array, int n) {
    int last_positive_index = -1;
    for (int i = 0; i < n; i++) {
        if (ptr_array[i] > 0) {
            last_positive_index = i;
        }
    }
    return last_positive_index;
}

double find_last_positive_value(double *ptr_array, int n) {
    int index = lpi(ptr_array, n);
    if (index != -1) {
        return ptr_array[index];
    } else {
        return -1;
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    double array[] = {1.2, -3.4, 5.6, -7.8, 9.0, -1.2};
    int n = sizeof(array)/sizeof(array[0]);
    int index = lpi(array, n);
    double number = find_last_positive_value(array, n);

    if (index != -1) {
        printf("Индекс последнего положительного элемента: %d\n", index);
        printf("Значение последнего положительного элемента: %lg\n", number);
    } else {
        printf("Положительных элементов нет.\n");
    }
}
