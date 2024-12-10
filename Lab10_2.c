#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define M_PI 3.14159265358979323846

double factorial(double n) {
    double fact = 1;
    while (n > 1.) {
		fact *= n;
		n -= 1.;
	}
	return fact;
}

double cosx(double x, int n) {
    double result = 0.0;
    double num = 1.0;
    int sign = 1;

    for (int i = 0; i < n; i++) {
        result += num;
        sign = -sign;
        num = num * x * x / factorial(n);
    }
    return result;
}

double cos_eps(double x, double eps) {
    double result = 1.0;
    double num = 1.0;
    int n = 0;
    int sign = 1;

    while (fabs(num) > eps) {
        result += num;
        sign = -sign;
        n++;
        num = sign * num * x * x / factorial(n);
    }
    return result;
}

int main() {
    double x;
    int n;
    double eps;

    printf("Введите значение x: ");
    scanf("%lf", &x);
    printf("Введите количество членов ряда: ");
    scanf("%d", &n);
    printf("Введите точность (epsilon): ");
    scanf("%lf", &eps);




    printf("| N|         cos_N|    отклонение|\n");
	for (int i = 0; i <= n; i++) {
		printf("|%2i|%14f|%14f|\n", i, cosx(x, i), fabs(cos(x)-cosx(x, i)));
	}
	printf("\n");
	printf("| N|        exp(N)|    отклонение|\n");
	for (int i = 0; i <= n; i++) {
		printf("|%2i|%14f|%14f|\n", i, cos_eps(x, i), fabs(exp(-x) - cos_eps(x, i)));
    }
    printf("cos(%.2f) с использованием стандартной библиотеки: %.10f\n", x, cos(x));
    printf("cos(%.2f) как сумма ряда с %d членами: %.10f\n", x, n, cosx(x, n));
    printf("cos(%.2f) через ряд Маклорена с точностью %.2lg: %.10f\n", x, eps, cos_eps(x, eps));
    
}
