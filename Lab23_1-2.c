#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
#include "list.h"

void loadTracks(List** head, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return;
    }

    char track[256];
    while (fgets(track, sizeof(track), file)) {
        track[strcspn(track, "\n")] = 0;
        insert(head, track);
    }

    fclose(file);
}

int main() {
    setlocale(LC_ALL, "RU");
    List* head;
    initList(&head);
    srand(time(NULL));

    loadTracks(&head, "tracks.txt");

    printf("Список до преобразования:\n");
    printList(head);

    List* current = head;
    while (current != NULL) {
        current->playCount = rand() % 10;
        current = current->next;
    }

    delete(&head, 5);

    printf("Список после преобразования:\n");
    printList(head);

    destroyList(&head);

    return 0;
}
