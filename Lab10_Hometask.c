#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define M_PI 3.14159265358979323846

void formulation() {
    printf("Это прямоугольный треугольник, у которого один угол равен 90 градусов.\n");
}

float area(int a, int b) {
    return 0.5 * a * b;
}

int drawShape(int a, int b, char s) {
    int i = 1;
    while (i <= a) {
        int j = 1;
        while (j <= b && j <= i) {
            printf("%c ", s);
            j++;
        }
        printf("\n");
        i++;
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
	char s;
	int a, b, с, b_temp;
	puts("Введите символ:");
	scanf_s("%c", &s);
	puts("Введите первый катет:");
	scanf_s("%i", &a);
	puts("Введите второй катет:");
	scanf_s("%i", &b);

	formulation();
    printf("Площадь треугольника: %.2f\n", area(a, b));
    drawShape(a, b, s);


}
