#include <stdio.h>
#include <math.h>
#include <locale.h>
#define M_PI 3.1415926535

#define SIZE 100

int main() {
    setlocale(LC_ALL, "RUS");
    double array[SIZE];
    double a = 0.0;
    int pCount = 0;

    for (int i = 0; i < SIZE; i++) {
        double x = 1.0 + (2.0 * i) / (SIZE - 1);
        array[i] = x * x - pow(cos(M_PI * x), 2);

        if (array[i] > 0) {
            a += array[i];
            pCount++;
        }
    }

    double pAverage = (pCount > 0) ? a / pCount : 0.0;

    printf("Имя массива: array\n");
    printf("Накопленное значение положительных элементов: %.2f\n", a);
    printf("Число положительных элементов: %d\n", pCount);
    printf("Среднее значение положительных элементов: %.2f\n", pAverage);

}
