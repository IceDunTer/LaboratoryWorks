#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    FILE *in;
    int num, sum = 0, count = 0;

    if ((in = fopen("studio.h", "r")) == NULL) {
        printf("Ошибка открытия файла для чтения\n");
        return 1;
    }

    while (!feof(in)) {
        if (fscanf(in, "%d", &num) == 1) {
            sum += num;
            count++;
        }
    }

    if (count == 0) {
        printf("Файл пуст или не содержит целых чисел\n");
        fclose(in);
        return 1;
    }
    
    double average = (double)sum / count;
    printf("Среднее арифметическое: %f\n", average);

    fclose(in);
}
