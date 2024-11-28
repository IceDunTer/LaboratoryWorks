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
	int size;
	puts("Введите размер массива (< 1000):");
	scanf_s("%i", &size);
	full_elements(array, size);
	put_elements(array, size);
	calc_elements(array, size);
	put_elements(array, size);
}
