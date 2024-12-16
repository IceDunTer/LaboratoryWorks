#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#define Pi 3.14159265358979323846

int main() {
    setlocale(LC_ALL, "RUS");
    double x, x1, tab;
    float y;
    int pick;
    FILE *file;

    puts("Введите начало интервала:");
    scanf("%lf", &x);
    puts("Введите край интервала:");
    scanf("%lf", &x1);
    puts("Введите шаг:");
    scanf("%lf", &tab);

    puts("Выберите действие:\n1) Запись в новый файл\n2) Дозапись в существующий файл");
    scanf("%d", &pick);

    if (pick == 1) {
        file = fopen("temp.txt", "w");
    } else if (pick == 2) {
        file = fopen("temp.txt", "a");
    } else {
        printf("Неверный выбор. Программа завершена.\n");
        return 1;
    }

    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return 1;
    }
    fprintf(file, "| (x)\t| f(x) |\n");

    for (double i = x; i <= x1 + 0.0000001; i += tab) {
        y = pow(i, 2) - pow(cos(Pi * i), 2);
        fprintf(file, "| (%.2lf)\t| %.2f |\n", i, y);
    }

    fclose(file);
    printf("Результаты табулирования записаны в файл temp.txt.\n");
}
