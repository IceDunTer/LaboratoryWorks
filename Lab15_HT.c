#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SPORTSMEN 20
#define SPORTS 5

void fill_elements(int arr[SPORTSMEN][SPORTS]) {
    for (int i = 0; i < SPORTSMEN; i++) {
        for (int j = 0; j < SPORTS; j++) {
            arr[i][j] = rand() % 10 + 1;
        }
    }
}

void print_array(int arr[SPORTSMEN][SPORTS]) {
    for (int i = 0; i < SPORTSMEN; i++) {
        for (int j = 0; j < SPORTS; j++) {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }
}

int sum(int arr[SPORTSMEN][SPORTS]) {
    int sum = 0;
    for (int j = 0; j < SPORTS; j++) {
        sum += arr[2][j];
    }
    return sum;
}

int main() {
    srand(time(NULL));
    int array[SPORTSMEN][SPORTS];

    fill_elements(array);
    printf("\t// Баллы спортсменов:\\\\\n");
    print_array(array);

    int total = sum(array);
    printf("\nОбщая сумма баллов, набранных третьим спортсменом: %i\n", total);
}
