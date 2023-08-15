#include "stringutils.h"
#include <string.h>
#include <stdio.h>
#include "list.h"

#define SOL -2
#define IOB -3

int is_whitespace(char c) {
    char whites[] = " \t\n\r\v\f";
    for (size_t i = 0; i < strlen(whites); i++) {
        if (whites[i] == c) {
            return 1;
        }
    }
    return 0;
}

char * left_trim(char * str) {
    size_t len = strlen(str);
    int index = -1;

    for (size_t i = 0; i < len; i++) {
        if (is_whitespace(str[i]) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1 || index == 0) {
        return str;
    }

    memmove(str, str + index, len - index + 1);

    return str;
}

char * right_trim(char * str) {
    size_t len = strlen(str);
    int index = -1;

    for (int i = len - 1; i > -1; i--) {
        if (is_whitespace(str[i]) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1 || index == len - 1) {
        return str;
    }

    str[index + 1] = '\0';
    return str;
}

char * trim(char * str) {
    left_trim(str);
    return right_trim(str);
}


void getl(List * dest) {
    int c = SOL;

    while (c != EOF && c != '\n') {
        if (c != SOL) {
            addToList(dest, c);
        }
        c = getc(stdin);
    }
}

void ltos(List * list, char * destination) {
    for (int i = 0; i < list->size; i++) {
        destination[i] = (char) getFromList(list, i);
    }

    destination[list->size] = '\0';
}
