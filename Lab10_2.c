#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define M_PI 3.14159265358979323846

unsigned int factorial(unsigned int b) {
    if (b == 1) {
        return 1;
    }
    return b * factorial(b - 1);
}

double arcctg_n(double x, int n) {
	return (M_PI/2 + (pow(-1, n+1)*pow(x, 2*n+1))/(2*n+1));
}

double arcctg_eps(double x, double eps) {

}

int main() {
	setlocale(LC_ALL, "RUS");
	double a, eps;
	int N;
	puts("Введите число [|x|<=1]:");
	scanf_s("%lg", &a);
	puts("Введите число повторений N:");
	scanf_s("%i", &N);
	puts("Введите число точность для ряда Маклорена:");
	scanf_s("%lg", &eps);

	printf("Арккотангенс числа функцией стандартной библиотеки: %lg\n", (M_PI/2 - atan(a)));
	printf("Арккотангенс числа функцией с количеством повторений N: %lg\n", arcctg_n(a, N));
	printf("");

}
