#include <stdio.h>
#include <string.h>
#define N 256

int main() {
    char str[N];
    int count = 0;

    printf("Type your string: ");
    fgets(str, sizeof(str), stdin);

    char *word = strtok(str, " \n");
    while (word != NULL) {
        if (strlen(word) <= 3) {
            count++; 
        }
        word = strtok(NULL, " \n");
    }

    printf("Amount words with length less than 3 symbs: %d\n", count);
}
