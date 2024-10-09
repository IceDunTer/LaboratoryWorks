#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");
	int m, n;
	int k = 0;
	int s = 0;

	puts("Введите 1-ое число:\n");
	scanf_s("%i", &m);
	puts("Введите 2-ое число:\n");
	scanf_s("%i", &n);

	for (int i = m; i >= n; i--) {
		s += i;
		k++;
	}
	printf("Выполнено %i раз\n", k);
	printf("Результат: %i", s);
}
