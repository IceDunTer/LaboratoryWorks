#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

typedef double (*math_func)(double);

double Y(double x) {
    return (x > 0) ? log(sqrt(x)) : 0;
}

double V(double x) {
    if (x > 1) {
        return sqrt(tan(x * x - 1)) - 2 * x;
    } else if (0 <= x && x <= 1) {
        return cos(x);
    } else {
        return 0;
    }
}

double S(double x) {
    return (x - 1) * (1 / (x + 1)) + pow((x - 1) / (x + 1), 3) / 3 + pow((x - 1) / (x + 1), 5) / 5 + pow((x - 1) / (x + 1), 7) / 7;
}

void tab(math_func func, double start, double end, double step) {
    printf(" x      |  f(x)\n");
    for (double x = start; x <= end; x += step) {
        printf("%7.2f  |  %7.4f\n", x, func(x));
    }
    printf("\n");
}

void calc(math_func func, double x) {
    printf("Значение функции при x = %.2f: %7.4f\n", x, func(x));
}

void plot(math_func func, double start, double end, double step) {
    tab(func, start, end, step);
}

int main() {
    setlocale(LC_ALL, "RUS");
    int choice, func_choice;
    double x, start, end, step;
    math_func selected_func;

    do {
        printf("\t\n// МЕНЮ \\\\\n");
        printf("1. Вычислить значение\n");
        printf("2. Табулировать\n");
        printf("3. Построить график выбранной функции\n");
        printf("0. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        printf("Выберите функцию:\n");
        printf("1. S(x)\n");
        printf("2. V(x)\n");
        printf("3. Y(x)\n");
        printf("Ваш выбор: ");
        scanf("%d", &func_choice);

        switch (func_choice) {
            case 1:
                selected_func = S;
                break;
            case 2:
                selected_func = V;
                break;
            case 3:
                selected_func = Y;
                break;
            default:
                printf("Некорректный выбор функции.\n");
                continue;
        }

        switch (choice) {
            case 1:
                printf("Введите значение x: ");
                scanf("%lf", &x);
                calc(selected_func, x);
                break;
            case 2:
                printf("Введите начало интервала: ");
                scanf("%lf", &start);
                printf("Введите конец интервала: ");
                scanf("%lf", &end);
                printf("Введите шаг табуляции: ");
                scanf("%lf", &step);
                tab(selected_func, start, end, step);
                break;
            case 3:
                printf("Введите начало интервала: ");
                scanf("%lf", &start);
                printf("Введите конец интервала: ");
                scanf("%lf", &end);
                printf("Введите шаг табуляции: ");
                scanf("%lf", &step);
                plot(selected_func, start, end, step);
                break;
            default:
                printf("Некорректный выбор действия.\n");
        }
    } while (!choice);

}
