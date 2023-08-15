#ifndef TOKENIZER_H_INCLUDED
#define TOKENIZER_H_INCLUDED

#include <stdlib.h>

typedef struct {
    size_t cursor;
    char * data;
    int finished;
} Tokenizer;

void initTokenizer(Tokenizer * tokenizer, char * data);
void freeTokenizer(Tokenizer * tokenizer);
void nextToken(Tokenizer * tokenizer, char * dest);
void reset(Tokenizer * tokenizer);
int isSpecialToken(char c);

#endif // TOKENIZER_H_INCLUDED
