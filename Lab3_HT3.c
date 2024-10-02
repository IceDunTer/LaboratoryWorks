#include <stdio.h>
#include <locale.h>
void main()
{
	setlocale(LC_ALL, "RUS");
	float ch1, ch2;
	puts("Введите числа 1 и 2\n");
	scanf("%f", &ch1);
	scanf("%f", &ch2);
	printf("|\ta * b\t\t|\ta + b\t\t|\ta - b\t\t|\ta / b\t\t|\n");
	printf("|%f * %f\t|%f + %f\t|%f - %f\t|%f / %f\t|\n", ch1, ch2, ch1, ch2, ch1, ch2, ch1, ch2);
	printf("|\t%f\t|\t%f\t|\t%f\t|\t%f\t|\n", ch1 * ch2, ch1 + ch2, ch1 - ch2, ch1 / ch2);
}
