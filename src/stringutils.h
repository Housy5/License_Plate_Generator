#ifndef STRINGUTILS_H_INCLUDED
#define STRINGUTILS_H_INCLUDED

#include <stdio.h>
#include "list.h"

char * left_trim(char * str);
char * right_trim(char * str);
char * trim(char * str);
int is_whitespace(char c);

void getl(List * dest);
void ltos(List * list, char * dest);

#endif // STRINGUTILS_H_INCLUDED
