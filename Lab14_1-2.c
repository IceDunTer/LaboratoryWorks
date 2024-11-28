#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <locale.h>
#define N 1000
#define Pi 3.14159265358979323846

void full_elements(double* ptr_array, int n) {
	double y;
	int count = 0;
	for (double i = 0; i <= n; i += sin(Pi*3/1.33)/2.22) {
		y = pow(i, 2) - pow(cos(Pi * i), 2);
		ptr_array[count] = y;
		count++;
	}
}

double sum_elems(double* ptr_array, int s, int e) {
	double summ = 0.;
	for (int i = s; i <= e; i++) {
		summ += ptr_array[i];
	}
	return summ;
}

int find_elem(double* ptr_array, int n, double elem) {
	ptr_array[0];
	for (int i = 0; i <= n; i++) {
		if (ptr_array[i] == elem) {
			return ptr_array[i];
			break;
		}
	}
}

int put_elements(double* ptr_array, int n) {
	
	for (int i = 0; i <= n; i++) {
		printf("a[%i] = %lg\n", i, ptr_array[i]);
	}
}

double* calc_elements(double* ptr_array, int n) {
	for (int i = 0; i <= n; i++) {
		ptr_array[i] = ptr_array[i] * 2;
	}
}

int main() {
	setlocale(LC_ALL, "RUS");
	double array[N];
	int size, start, end;
	double num;
	puts("Введите размер массива (< 1000):");
	scanf_s("%i", &size);
	puts("Введите начальный индекс:");
	scanf_s("%i", &start);
	puts("Введите конечный индекс:");
	scanf_s("%i", &end);
	puts("Введите число для поиска в массиве:");
	scanf_s("%lg", &num);

	full_elements(array, size);
	put_elements(array, size);
	printf("\n%lg", sum_elems(array, start, end));
	printf("\nНомер ближайшего индекса для числа %lg - %i", num, find_elem(array, size, num));

}
