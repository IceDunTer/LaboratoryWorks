#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");
	int cycle;
	puts("Введите число повторений знака:\n");
	scanf("%i", &cycle);

	printf("+!");
	for (int start = 1; start <= cycle/2; start++) {
		putchar('*');
		putchar('!');
	}
	if (cycle % 2 == 1)
		printf("*!");
	for (int start = 1; start <= cycle / 2; start++) {
		putchar('-');
		putchar('!');
	}
	puts("+!");
}
