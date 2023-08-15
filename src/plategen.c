
#include <stdlib.h>
#include <string.h>

#include "tokenizer.h"

char getRandomCharacter() {
    char result = '\0';

    int min = 'A';
    int max = 'Z' + 1;
    result = (char) (rand() % (max - min)) + min;

    return result;
}

char getRandomNumber() {
    return (char) (rand() % 10) + '0';
}

char * generatePlate(char * format, char * dest) {
    Tokenizer tokenizer;
    initTokenizer(&tokenizer, format);
    size_t counter = 0;

    while (tokenizer.finished == 0) {
        char token[3];
        nextToken(&tokenizer, token);

        if (strcmp(token, "%d") == 0) {
            dest[counter] = getRandomNumber();
        }

        if (strcmp(token, "%c") == 0) {
            dest[counter] = getRandomCharacter();
        }

        if (strlen(token) == 1) {
            dest[counter] = token[0];
        }

        counter++;
    }

    dest[counter] = '\0';

    return dest;
}

void initRandomizer() {
    srand((unsigned) time(NULL));
}
