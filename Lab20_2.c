#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void processFile(const char *ifn) {
    FILE *in, *out;
    char ofn[256];
    float num;

    if ((in = fopen(ifn, "r")) == NULL) {
        printf("Ошибка открытия файла для чтения\n");
        return;
    }
    snprintf(ofn, sizeof(ofn), "%sparity1.dat", ifn);

    if ((out = fopen(ofn, "w")) == NULL) {
        printf("Ошибка открытия файла для записи\n");
        fclose(in);
        return;
    }

    while (fscanf(in, "%f", &num) == 1) {
        if (num > 0) {
            num /= 4;
        }
        fprintf(out, "%f\n", num);
    }

    fclose(in);
    fclose(out);
    printf("Обработка завершена. Результат записан в файл %s\n", ofn);
}

int main() {
    setlocale(LC_ALL, "RUS");
    char inputFileName[256];

    printf("Введите имя входного файла: ");
    if (scanf("%255s", inputFileName) != 1) {
        printf("Ошибка ввода имени файла\n");
        return 1;
    }
    processFile(inputFileName);
}
