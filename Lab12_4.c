#include <stdio.h>
#include <locale.h>

int third() {
    int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int* ptr = arr;
    printf("Элементы массива, доступные через указатель с увеличением на 2:\n");
    for (int i = 0; i < 10; i += 2) {
        printf("arr[%i] = %i, адрес = %p\n", i, *(ptr + i), &arr[i]);
    }
}

int fourth() {
    int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int* ptr = arr;
    printf("Элементы массива, проходя его с последнего числа на первое:\n");
    int* ptr_a = &arr[9];
    for (int i = 9; i >= 0; i--) {
        printf("arr[%i] = %i, адрес = %p\n", i, *ptr_a--, &arr[i]);
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int* ptr = arr;
    int* ptr_a = &arr[0];
    puts("12.4.1)");
    printf("Элементы массива:\n");
    for (int i = 0; i < 10; i++) {
        printf("arr[%i] = %i, адрес = %p\n", i, *(ptr + i), &arr[i]);
    }

    printf("12.4.2)\n");
    printf("%i - %p\n", *ptr_a+1, ptr_a+1);
    printf("%i - %p\n", *ptr_a+4, ptr_a + 4);
    printf("%i - %p\n", *ptr_a-2, ptr_a - 2);

    printf("12.4.3) \n");
    printf("Элементы массива, доступные через указатель с увеличением на 2:\n");
    for (int i = 0; i < 10; i += 2) {
        printf("arr[%i] = %i, адрес = %p\n", i, *(ptr + i), &arr[i]);
    }
    
    printf("12.4.4) \n");
    printf("Элементы массива, проходя его с последнего числа на первое:\n");
    ptr = &arr[9];
    for (int i = 9; i >= 0; i--) {
        printf("arr[%i] = %i, адрес = %p\n", i, *(ptr--), &arr[i]);
    }
}
