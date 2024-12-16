#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "RUS");
    char fname[20] = "number.txt";
    FILE *out;

    if ((out = fopen(fname, "a")) == NULL) {
        printf("Ошибка открытия файла для записи");
        return 0;
    }
    srand(time(NULL));
    int random_number = rand() % 10;

    fprintf(out, "%i\n", random_number);
    fclose(out);
    return 1;
}
