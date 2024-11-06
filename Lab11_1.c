#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define b 10

int main()
{
	setlocale(LC_ALL, "RUS");
	float A[b], B[b], temp;
	double mid = 0;
	double ans;
	for (int i = 0; i < b; i++) 
	{
		printf("a[%d] = ", i + 1);
		scanf_s("%f", &temp);
		A[i] = temp;
		B[i] = temp + 1;
		mid += (temp + 1);
	}
	printf("Индекс \t| Исх.Знач \t| Нов.Знач\n");
	for (int i = 0; i < b; i++) {
		printf("%d \t| \t%lg \t| %lg \n", i, A[i], B[i]);
	}
	ans = mid / b;
	printf("Среднее арифметическое: %lg", ans);

}
