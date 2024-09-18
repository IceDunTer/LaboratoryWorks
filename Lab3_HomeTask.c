#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	setlocale(LC_ALL, "RUS");
	int a;
	puts("Введите длину ребра куба:\n");
	scanf("%i", &a);
	printf("Объём куба равен %i, а его площадь боковой поверхности - %i", a*a*a, 4*a*a);
	
}
