#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define K 10
#define N 100

int main() {
    setlocale(LC_ALL, "RUS");
    int counter[K] = {0}; 
    int array[N];

    srand(time(0));

    for (int i = 0; i < N; ++i) {
        array[i] = rand() % K + 1;
    }

    for (int i = 0; i < N; ++i) {
        counter[array[i] - 1]++;
    }

    int max = counter[0];
    for (int i = 1; i < K; ++i) {
        if (counter[i] > max) {
            max = counter[i];
        }
    }

    for (int r = max; r > 0; --r) {
        for (int i = 0; i < K; ++i) {
            if (counter[i] >= r) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < K; ++i) {
        printf("%d ", i + 1);
    }
    printf("\n");
}
