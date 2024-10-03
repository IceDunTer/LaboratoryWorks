#include <stdio.h>
#include <locale.h>

// Контрольные значения: a - "Это буква", 2 - "Это цифра", p - "Неизвестный символ", 8 - "Неизвестный символ"

int main() {
	setlocale(LC_ALL, ("RUS"));
	char c;
	printf("Введите символ: ");
	scanf_s("%c", &c);
	switch (c)
	{
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
			printf("Это цифра.\n");
			break;
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
			printf("Это буква. \n");
			break;
		default:
			printf("Неизвестный символ\n");
	}
}
