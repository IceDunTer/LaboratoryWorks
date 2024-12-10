#include <stdio.h>
#include <math.h>
#include <locale.h>
#define N 10

void printBytes(void* ptr, size_t size) {
    unsigned char* byte = (unsigned char*) ptr;
    for (size_t i = 0; i < size; i++) {
        printf("%02x\n", byte[i]);
    }
}

int main() {
    int x = 0x12345678;
    float a = 12345.0;
    double b = 12345.0;

    printf("int x:\n");
    printBytes(&x, sizeof(x));
    printf("float a:\n");
    printBytes(&a, sizeof(a));
    printf("double d:\n");
    printBytes(&b, sizeof(b));
}