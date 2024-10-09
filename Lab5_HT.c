#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define _USE_MATH_DEFINES

int main() {
	setlocale(LC_ALL, "RUS");
	double A, B, C, D, x, y, z, v;

	x = 3.74/100;
	y = -0.825;
	z = 0.16*100;

	A = 1 + pow(sin(x + y), 2);
	B = fabs(x - (2 * y / 1 + x * x * y * y));
	C = pow(x, fabs(y));
	D = pow(cos(atan(1 / z)), 2);

	v = A / B * C + D;

	printf("x = %lg\ny = %lg\nz = %lg\nv = %lg", x, y, z, v);

}
