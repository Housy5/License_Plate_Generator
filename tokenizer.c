#include "tokenizer.h"

#include <stdlib.h>
#include <string.h>

void initTokenizer(Tokenizer * tokenizer, char * data) {
    tokenizer->cursor = 0;
    tokenizer->data = data;
    tokenizer->finished = 0;
}

void freeTokenizer(Tokenizer * tokenizer) {
    tokenizer->cursor = 0;
    free(tokenizer->data);
    tokenizer->data = NULL;
    free(tokenizer);
}

int isSpecialToken(char c) {
    char specials[] = "dc";
    size_t len = strlen(specials);

    for (size_t i = 0; i < len; i++) {
        if (specials[i] == c) {
            return 1;
        }
    }

    return 0;
}

void nextToken(Tokenizer * tokenizer, char * dest) {
    size_t len = strlen(tokenizer->data);
    size_t counter = 0; // counts the elements added to dest.

    for  (size_t i = tokenizer->cursor; i < len; i++) {
        dest[counter] = tokenizer->data[i];
        char next = tokenizer->data[i + 1];
        counter++;
        if (tokenizer->data[i] == '%' && isSpecialToken(next)) {
            continue;
        }
        break;
    }

    dest[counter] = '\0';

    tokenizer->cursor += counter;

    if (tokenizer->cursor == len) {
        tokenizer->finished = 1;
    }
}

void reset(Tokenizer * tokenizer) {
    tokenizer->cursor = 0;
    tokenizer->finished = 0;
}
