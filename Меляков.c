#include <stdio.h>
#include <locale.h>

void name() {
	setlocale(LC_ALL, "RUS");
	puts("* * * * * * * * * * * * * * * * * * * * * *");
	puts("*                                         *");
	puts("* ����: ���������� ����������� ���������� *");
	puts("*                                         *");
	puts("*   �������� ������� �.�.                 *");
	puts("*                                         *");
	puts("* * * * * * * * * * * * * * * * * * * * * *");
	getchar();
}

void date() {
	setlocale(LC_ALL, "RUS");
	puts("   _         __  __      __   __  ");
	puts("  | | /|    |  |   |    |  | |__  ");
	puts("   /   |    |  | --|    |  | |  | ");
	puts("  /_   |    |__| __|    |__| |__| ");
	getchar();
}

void main() {
	name();
	date();
}