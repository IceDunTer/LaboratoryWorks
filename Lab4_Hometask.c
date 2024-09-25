#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
    setlocale(LC_ALL, "RUS");
    int x;

    puts("Напиишите число, которое должен заплатить один человек:\n");
    scanf("%i", &x);
    int x_quad = x * 4;
    printf("Четыре человека оплатят официанту %lg рублей\n", (double)x_quad * 0.15);
}