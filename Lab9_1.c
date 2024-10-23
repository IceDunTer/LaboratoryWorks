#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");
	int ROW = 9, COL = 9;
	for (int row = 1; row <= ROW; row++)
	{
		for (int col = 1; col <= row; col++) {
			printf("%5d", col * row);
		}
		printf("\n");
	}
	system("pause");

	int stop = 11;
	for (int i = 1; i < stop; i++) {
		for (int j = 1; j < stop; j++) {
			printf("%5d", j);
		}
		printf("\n");
	}


}
