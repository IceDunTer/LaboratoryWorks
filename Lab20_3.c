#include <stdio.h>
#include <stdlib.h>

void processFile(const char *ifn, const char *ofn) {
    FILE *in, *out;
    int c;

    if ((in = fopen(ifn, "r")) == NULL) {
        printf("Ошибка открытия файла для чтения\n");
        return;
    }

    if ((out = fopen(ofn, "w")) == NULL) {
        printf("Ошибка открытия файла для записи\n");
        fclose(in);
        return;
    }

    while ((c = fgetc(in)) != EOF) {
        if (c == ' ') {
            fputc('o', out);
        } else if (c == 'o' || c == 'O') {
            fputc(' ', out);
        } else {
            fputc(c, out);
        }
    }

    fclose(in);
    fclose(out);

    printf("Обработка завершена. Результат записан в файл %s\n", ofn);
}

int main() {
    char outputFileName[256];

    printf("Введите имя выходного файла: ");
    if (scanf("%255s", outputFileName) != 1) {
        printf("Ошибка ввода имени файла\n");
        return 1;
    }

    processFile("winter.txt", outputFileName);

    return 0;
}
