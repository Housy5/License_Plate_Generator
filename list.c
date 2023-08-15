#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void initList(List * list, size_t initialCap) {
    list->cap = initialCap;
    list->size = 0;
    list->data = malloc(initialCap * sizeof(void*));

    if (list->data == NULL) {
        perror("Memory allocation error!");
        exit(EXIT_FAILURE);
    }
}

void addToList(List * list, void* element) {
    if (list->size == list->cap) {
        list->cap *= 2;
        list->data = realloc(list->data, list->cap * sizeof(void*));

        if (list->data == NULL) {
            perror("Memory allocation error!");
            exit(EXIT_FAILURE);
        }
    }

    list->data[list->size] = element;
    list->size++;
}

void * getFromList(List * list, size_t index) {
    if (index >= list->size) {
        return NULL;
    }

    return list->data[index];
}

void * removeFromList(List * list, size_t index) {
    if (index >= list->size) {
        return NULL;
    }

    void * element = list->data[index];

    for (int i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }

    list->size--;

    if (list->size < list->cap / 2) {
        list->cap /= 2;
        list->data = realloc(list->data, list->cap * sizeof(void*));

        if (list->data == NULL) {
            perror("Memory allocation error!");
            exit(EXIT_FAILURE);
        }
    }

    return element;
}

void clearList(List * list) {
    list->size = 0;
    free(list->data);
    list->data = malloc(list->cap * sizeof(void*));
}

void freeList(List * list) {
    free(list->data);
    list->data = NULL;
    list->size = 0;
    list->cap = 0;
    free(list);
}
