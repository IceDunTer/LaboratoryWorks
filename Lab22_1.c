#include <stdio.h>
#include <locale.h>
#include <math.h>

#define M_PI 3.141592653

double y(double x, double* result) {
    if (x > 0) {
        *result = log(fabs(sqrt(x)));
    }
    else {
        *result = 0;
    }
}

double v(double x, double* result) {
    if (x > 1) {
        double arg = x * x - 1;
        if (fabs(arg) < M_PI / 2) { // Проверка на неопределенность тангенса
            *result = sqrt(tan(arg));
        }
        else {
            *result = -9999; // Возвращаем -9999, если аргумент тангенса некорректен
        }
    }
    else if (x >= 0 && x <= 1) {
        *result = -2 * x;
    }
    else if (x < 0) {
        *result = exp(cos(x));
    }
}

double s(double x, double* result) {
    if (x != -1) { // Проверка на деление на ноль
        double term = (x - 1) / (x + 1);
        *result = term + 1 / 3 * pow(term, 3) + 1 / 5 * pow(term, 5) + 1 / 7 * pow(term, 7);
    }
    else {
        *result = -9999; // Возвращаем -9999, если знаменатель равен нулю
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    double x_start = 0.1, x_end = 10.0;
    float step = 0.1f;
    int check;

    puts("Введите число для указателя: ");
    scanf("%i", &check);
    printf("y(x) \t| y(0.0)\n");
    if (check == 1) {
        for (double x = x_start; x <= x_end; x += step) {
            double y_result;
            y(x, &y_result);
            printf("%lg \t| %4.2f\n", x, y_result);
        }
    }
    else if (check == 2) {
        for (double x = x_start; x <= x_end; x += step) {
            double v_result;
            v(x, &v_result);
            printf("%lg \t| %4.2f\n", x, v_result);
        }
    }
    else if (check == 3) {
        for (double x = x_start; x <= x_end; x += step) {
            double s_result;
            s(x, &s_result);
            printf("%lg \t| %4.2f\n", x, s_result);
        }
    }
    else {
        printf("Неправильно введено значение указателя!");
    }

    return 0;
}
