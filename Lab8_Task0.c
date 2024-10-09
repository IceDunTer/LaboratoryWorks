#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");
	int cycle;
	puts("Введите число повторений знака:\n");
	scanf_s("%i", &cycle);

	puts('+!');
	for (int start = 1; start <= cycle/2; start++) {
		putchar('*');
		putchar('!');
	}
	if (cycle % 2 == 1)
		puts('*!');
	for (int start = 1; start <= cycle / 2; start++) {
		putchar('-');
		putchar('!');
	}
	puts('+!');
}
