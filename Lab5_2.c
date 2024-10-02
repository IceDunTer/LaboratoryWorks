#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define _USE_MATH_DEFINES

int main() {
	setlocale(LC_ALL, "RUS");
	double x, y, p, a, b;

	p = 0.5;
	puts("Введи число Х\n");
	scanf_s("%lg", &x);
	a = log((p * p) + (x * x * x));
	b = exp(pow(fabs(x), 1. / 2));
	y = pow(a, 3.) / pow(b, 2.);

	printf("X = %lg, а Y = %.4f", x, y);

}
