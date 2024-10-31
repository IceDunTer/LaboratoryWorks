#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

double f1(double x) {
	double y = x > 3 ? 1 / (pow(x, 3) + 3) : pow(x, 2) - 3 * x + 9;
	return y;
}

double f2(double x) {
	double y = x * exp(sin(pow(x, 2)));
	return y;
}

int main() {
	setlocale(LC_ALL, "RUS");
	double x;
	puts("Введите X:");
	scanf_s("%lg", &x);

	printf("F1(x) = %lf\nF2(x) = %lg\n\n", f1(x), f2(x));
	printf("Произведение ф-ций: %lg\nРазность квадратов функции: %lg\nУдвоенная сумма: %lg", f1(x) * f2(x), pow(f1(x), 2) - pow(f2(x), 2), (2 * f1(x)) + (2 * f2(x)));
}
