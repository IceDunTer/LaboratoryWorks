#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

// Контрольные примеры:
// 3, 1 = 3
// 24, 2 = 4
// 256, 1 = 2

int main() {
    setlocale(LC_ALL, "RUS");
	int x, y, x_len;
	puts("Напишите ваше число:\n");
	scanf("%i", &x);
	puts("Какую цифру вывести: 1 - первую, 2 - последнюю?\n");
	scanf("%i", &y);

	x_len = 1 + (int)log10(x);

	if (x_len == 1) printf("У числа только одна цифра - %i", x);
	else if (y == 1 && x_len == 3) printf("Первая цифра числа - %i", x / 100);
	else if (y == 1 && x_len == 2) printf("Первая цифра числа - %i", x / 10);
	else printf("Последняя цифра числа - %i", x % 10);
}
