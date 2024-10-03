#define _CRT_SECURE_NO_DEPRECATE 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

// 2,22 + 3,33 = 5,55; 61,25-41,39=19,86

int main() {
	setlocale(LC_ALL, "RUS");
	char symb;
	float a, b;
	puts("Напишите уравнение (+, -, *, /, ^):\n");
	scanf("%f %c %f", &a, &symb, &b);

	switch (symb) {
		case '+': 
			printf("=%.2f", a + b);
			break;
		case '-': 
			printf("=%.2f", a - b);
			break;
		case '*': 
			printf("=%.2f", a * b);
			break;
		case '/': 
			printf("=%.2f", a / b);
			break;
		case '^':
			printf("=%.2f", pow(a, b));
		default: 
			printf("Неверно указано действие!");
			break;

	}
}
