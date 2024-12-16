#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double getDouble(double min, double max) {
    return min + (double)(rand()) / (double)(RAND_MAX / (max - min));
}

void createDArray(double a[], int sizeA, double c[], int sizeC, double d[], int *sizeD) {
    int posAIndex = 0, negCIndex = 0, dIndex = 0;

    double positiveA[sizeA];
    for (int i = 0; i < sizeA; i++) {
        if (a[i] > 0) {
            positiveA[posAIndex++] = a[i];
        }
    }

    double negativeC[sizeC];
    for (int i = 0; i < sizeC; i++) {
        if (c[i] < 0) {
            negativeC[negCIndex++] = c[i];
        }
    }

    int minLength = (posAIndex < negCIndex) ? posAIndex : negCIndex;
    for (int i = 0; i < minLength; i++) {
        d[dIndex++] = positiveA[i];
        d[dIndex++] = negativeC[i];
    }
    for (int i = minLength; i < posAIndex; i++) {
        d[dIndex++] = positiveA[i];
    }
    for (int i = minLength; i < negCIndex; i++) {
        d[dIndex++] = negativeC[i];
    }
    *sizeD = dIndex;
}

int main() {
    srand(time(NULL));

    int size = 10;
    double a[size], b[size], c[size];
    double d[size * 2];
    int sizeD;

    for (int i = 0; i < size; i++) {
        a[i] = getDouble(-50, 50);
        b[i] = getDouble(-50, 50);
        c[i] = getDouble(-50, 50);
    }

    printf("Массив a: ");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", a[i]);
    }
    printf("\n");

    printf("Массив b: ");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", b[i]);
    }
    printf("\n");

    printf("Массив c: ");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", c[i]);
    }
    printf("\n");

    createDArray(a, size, c, size, d, &sizeD);

    printf("Новый массив d: ");
    for (int i = 0; i < sizeD; i++) {
        printf("%.2f ", d[i]);
    }
}
