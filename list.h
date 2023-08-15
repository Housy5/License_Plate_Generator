#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stddef.h>

typedef struct {
    void** data;
    size_t size;
    size_t cap;
} List;

void initList(List* list, size_t initialCap);
void* getFromList(List* list, size_t index);
void* removeFromList(List * list, size_t index);
void addToList(List* list, void* element);
void freeList(List* list);
void clearList(List* list);

#endif
