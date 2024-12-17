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
    printf("x\t|  f(x)\n");
    for (double x = start; x <= end; x += step) {
        printf("%lg\t|  %lg\n", x, func(x));
    }
    printf("\n");
}

double calc(math_func prtf, double *x, int n) {
    double product = 1.0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        double y = prtf(x[i]);
        if (y > 0 && y < 3.2) {
            product *= y;
            count++;
        }
    }

    return (count > 0) ? product : 0;
}

void perform_operation(math_func func, double *x, int n) {
    double result = calc(func, x, n);
    printf("Произведение значений функции, для которых 0 < y < 3.2: %7.4f\n", result);
}

void plot(math_func func, double start, double end, double step) {
    tab(func, start, end, step);
}

int main() {
    setlocale(LC_ALL, "RUS");
    int choice, func_choice;
    double start, end, step;
    int n;
    math_func selected_func;

    do {
        printf("\nМЕНЮ\n");
        printf("1. Вычислить значение\n");
        printf("2. Табулировать\n");
        printf("3. Выполнить операцию\n");
        printf("4. Построить график выбранной функции\n");
        printf("0. Выход\n");
        printf("Выберите действие: ");
        scanf("%i", &choice);

        if (choice == 0) {
            break;
        }

        printf("Выберите функцию:\n");
        printf("1. S(x)\n");
        printf("2. V(x)\n");
        printf("3. Y(x)\n");
        printf("Ваш выбор: ");
        scanf("%i", &func_choice);

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
            case 1: {
                double x;
                printf("Введите значение x: ");
                scanf("%lg", &x);
                printf("Значение функции при x = %.2lg: %.4lg\n", x, selected_func(x));
                break;
            }
            case 2:
                printf("Введите начало интервала: ");
                scanf("%lg", &start);
                printf("Введите конец интервала: ");
                scanf("%lg", &end);
                printf("Введите шаг табуляции: ");
                scanf("%lg", &step);
                tab(selected_func, start, end, step);
                break;
            case 3: {
                printf("Введите количество значений x: ");
                scanf("%i", &n);
                double x[n];
                printf("Введите значения x:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%lg", &x[i]);
                }
                perform_operation(selected_func, x, n);
                break;
            }
            case 4:
                printf("Введите начало интервала: ");
                scanf("%lg", &start);
                printf("Введите конец интервала: ");
                scanf("%lg", &end);
                printf("Введите шаг табуляции: ");
                scanf("%lg", &step);
                plot(selected_func, start, end, step);
                break;
            default:
                printf("Некорректный выбор действия.\n");
        }
    } while (!choice);
}
