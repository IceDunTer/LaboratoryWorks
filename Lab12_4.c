#include <stdio.h>
#include <locale.h>

int third() {
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *ptr = arr;
    printf("Элементы массива, доступные через указатель с увеличением на 2:\n");
    for (int i = 0; i < 10; i += 2) {
        printf("arr[%d] = %d\n", i, *(ptr + i));
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *ptr = arr;
    int *ptr_a = &arr[0];

    printf("Элементы массива:\n");
    for (int i = 0; i < 10; i++) {
        printf("arr[%i] = %i, адрес = %p\n", i, *(ptr + i), &arr[i]);
    }
    printf("\n");
    printf("%i - %p\n", *ptr_a++, ptr_a++);
    printf("%i - %p\n", *ptr_a+4, ptr_a+4);
    printf("%i - %p\n", *ptr_a-2, ptr_a-2);
}
