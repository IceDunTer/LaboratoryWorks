#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 40

int main() {
	char name[N];
	char hello[30] = "HELLO, ";
	printf("What's your name?\n");
	scanf("%s\0", &name);
	strcat(hello, name);

	int A = strlen(hello);

	for (int i = 0; i < A; i++) {
		hello[i] = toupper(hello[i]);
	}
	printf("13.1) %s", hello);

	while (N > A) {
		printf("!");
		A++;
	}
	printf("\n");

	hello[0] = tolower(hello[0]);
	printf("\n13.2) %s", hello);


}
