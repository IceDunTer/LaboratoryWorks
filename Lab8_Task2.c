#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define Pi 3.14159265358979323846

int main() {
	setlocale(LC_ALL, "RUS");
	double x, x1, tab;
	float y;
	puts("Введите начало интервала:\n");
	scanf("%lf", &x);
	puts("Введите край интервала:\n");
	scanf("%lf", &x1);
   	puts("Введите шаг:\n");
	scanf("%lf", &tab);
	printf("| ");
	printf("(x)\t");
	printf("| f(x)");
	printf("|\n");
	for (double i = x; i<=x1+0.0000001; i += tab) {
	    y = pow(i, 2) - pow(cos(Pi * i), 2);
	    printf("| ");
	    printf("(%.2lf)", i);
	    printf("| %.2f", y);
	    printf("|\n");
	} 
}
