#ifndef LIST_H
#define LIST_H

struct listitem {
    char* track;
    int playCount;
    struct listitem* next;
};

typedef struct listitem List;

void initList(List**);
void insert(List**, char*);
void printList(List*);
void delete(List**, int);
void destroyList(List**);

#endif
