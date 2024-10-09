#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define Pi 3.14159265358979323846

// y = x^2 - cos^2 пx [1;3]
// y = 2
int main() {
	setlocale(LC_ALL, "RUS");
	double x;
	float y;
	int tab;
	puts("Введите Х в интервале [1;3]:\n");
	scanf_s("%lg", &x);

	y = pow(x, 2) - pow(cos(Pi * x), 2);

	puts("Введите шаг табуляции:\n");
	scanf_s("%i", &tab);

	printf("| ");
	printf("(x)");
	for (int i = 0; i <= tab; i++) {
		printf("\t");
	}
	printf("| f(x)");
	for (int i = 0; i <= tab; i++) {
		printf("\t");
	}
	printf("|\n");

	printf("| ");
	printf("(%.2lg)", x);
	for (int i = 0; i <= tab; i++) {
		printf("\t");
	}
	printf("| %.2f", y);
	for (int i = 0; i <= tab; i++) {
		printf("\t");
	}
	printf("|");


}
