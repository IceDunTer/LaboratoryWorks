#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	setlocale(LC_ALL, "RUS");
	float a, b, a1, b1;

	puts("Введите число А:\n");
	scanf("%f", &a);
	puts("Введите число B:\n");
	scanf("%f", &b);
	printf("|\t\ta * b\t\t|\t\ta + b\t\t|\t\ta - b\t\t|\n");
	printf("|\t%f * %f\t|\t%f + %f\t|\t%f - %f\t|\n", a, b, a, b, a, b);
	printf("|\t\t%f\t|\t\t %f\t|\t\t%f\t|\n", a*b, a+b, a-b);
}
