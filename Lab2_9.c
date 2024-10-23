#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");
	long int a, counter = 0, half, digit, index = 1, num, first = 0, second = 0, last, lastCounter = 0;
	int check = 1;
	while (check)
	{
		index = 1;
		first = 0;
		second = 0;
		lastCounter = 0;
		counter = 0;
		puts("Ввeдите произвольное длинное число:");
		scanf_s("%ld", &a);

		num = a;
		last = num % 10;

		while (a > 0) {
			counter++;
			a /= 10;
		}
		half = counter / 2;

		while (num > 0) {
			digit = num % 10;
			num /= 10;

			if (digit == last) lastCounter++;

			if (index <= half)
				second += digit;
			else
				first += digit;

			index++;

		}
		printf("11) Количество цифр: %ld, Сумма первой половины: %ld, сумма второй половины: %ld\n", counter, first, second);
		printf("2) Последняя цифра числа - %ld, а количство ее повторений - %ld\n", last, lastCounter);
		
		puts("Продолжить? Да - 1, нет - 0");
		scanf_s("%i", &check);
		if (check == 0) break;
	}
	
}

