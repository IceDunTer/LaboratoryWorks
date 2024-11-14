#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "RUS");
    short int a;
    short int *p = &a;
    p+=2;
    int sizeOfShortInt = (int)(p - &a);
    printf("Размер short int в байтах: %d\n", sizeOfShortInt);
}
