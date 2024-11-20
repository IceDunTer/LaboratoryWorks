#include <stdio.h>
#include <locale.h>
#include <math.h>

double y(double x, double* result) {
	if (x > 0) *result = log(fabs(sqrt(pow(x, 3))));
	else *result = 0;
}

double v(double x, double *result) {
	if (x > 1) *result = sqrt(tan(x * x - 1));
	else if (x >= 0 && x <= 1) *result = -2 * x;
	else if (x < 0) *result = exp(cos(x));
}

double s(double x, double *result) {
	*result = (x - 1) / (x + 1) +
		1 / 3 * pow((x - 1) / (x + 1), 3) +
		1 / 5 * pow((x - 1) / (x + 1), 5) +
		1 / 7 * pow((x - 1) / (x + 1), 7);
}

int main() {
	double x_start = 0.1, x_end = 10.0;
	float step = 0.1f;
	int check;

	puts("Vvedite chislo dlya ukazatelya: ");
	scanf_s("%i", &check);
	printf("y(x) \t| y(0.0)\n");
	if (check == 1) {
		for (double x = x_start; x <= x_end; x += step) {
			double y_result;
			y(x, &y_result);
			printf("%lg \t| %4.2f\n", x, y_result);
		}
	}
	else if (check == 2) {
		for (double x = x_start; x <= x_end; x += step) {
			double v_result;
			v(x, &v_result);
			printf("%lg \t| %4.2f\n", x, v_result);
		}
	}
	else if (check == 3) {
		for (double x = x_start; x <= x_end; x += step) {
			double s_result;
			s(x, &s_result);
			printf("%lg \t| %4.2f\n", x, s_result);
		}
	}
	else printf("Nepravil'no vvedeno znachenie ukazatelya!");
}
