#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void initList(List** head) {
    *head = NULL;
}

void insert(List** head, char* track) {
    List* newItem = (List*)malloc(sizeof(List));
    if (newItem == NULL) {
        perror("Ошибка выделения памяти");
        exit(EXIT_FAILURE);
    }
    newItem->track = _strdup(track);
    if (newItem->track == NULL) {
        perror("Ошибка выделения памяти");
        free(newItem);
        exit(EXIT_FAILURE);
    }
    newItem->playCount = 0;
    newItem->next = NULL;

    if (*head == NULL) {
        *head = newItem;
    }
    else {
        List* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newItem;
    }
}

void printList(List* head) {
    List* current = head;
    int count = 1;
    while (current != NULL) {
        printf("%d. %s (Проиграно: %d)\n", count, current->track, current->playCount);
        current = current->next;
        count++;
    }
    printf("\n");
}

void delete(List** head, int playCount) {
    List* current = *head;
    List* prev = NULL;

    while (current != NULL) {
        if (current->playCount > playCount) {
            if (prev == NULL) {
                *head = current->next;
            }
            else {
                prev->next = current->next;
            }
            List* temp = current;
            current = current->next;
            free(temp->track);
            free(temp);
        }
        else {
            prev = current;
            current = current->next;
        }
    }
}

void destroyList(List** head) {
    List* current = *head;
    List* nextItem;
    while (current != NULL) {
        nextItem = current->next;
        free(current->track);
        free(current);
        current = nextItem;
    }
    *head = NULL;
}
