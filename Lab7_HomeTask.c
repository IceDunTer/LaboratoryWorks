#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");
	int x;
	puts("Введите двузначное число:\n");
	scanf_s("%i", &x);

	int x_last = x % 10;

	switch (x_last) {
	case 0:
	case 1:
	case 2:
	case 3:
	case 5:
	case 7:
		printf("Последняя цифра (%i) - простая", x_last);
		break;
	case 4:
	case 6:
	case 8:
	case 9:
		printf("Последняя цифра (%i) - сложная", x_last);
		break;
	}
}
