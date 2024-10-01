#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

// Контрольные примеры:
// X=2, Y=-1 - подходит
// X=3, Y=1 - не подходит

int main() {
    setlocale(LC_ALL, "RUS");
	int x, y;
	puts("Введите координату Х:\n");
	scanf("%i", &x);
	puts("Введите координату Y:\n");
	scanf("%i", &y);

	if (((x >= -2 && x <= 2) && (y >= 0 && y <= 4)) || ((x >= -4 && x <= 5) && (y >= -3 && y <= 0))) puts("Точка принадлежит закрашенным областям");
	else puts("Точка не принадлежит закрашенным областям");
}
