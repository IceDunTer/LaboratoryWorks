#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define m_row 100
#define m_col 100

int main() {
    setlocale(LC_ALL, "RUS");
    int row, col;
    double ans, min = 99999., max = -99999.;

    puts("Введите количество строк:");
    scanf("%i", &row);
    puts("Введите количество столбцов:");
    scanf("%i", &col);

    double arr[m_row][m_col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = i + j / 10.;
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%.2f ", arr[i][j]);
            ans = arr[i][j];
            if (arr[i][j] < min) {
                min = arr[i][j];
            }
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
        printf("\n");
    }
    printf("Число в крайнем правом нижнем углу: %lg\n", arr[row - 1][col - 1]);
    printf("Минимальное число: %lg, максимальное: %lg\n", min, max);
}
