#include <stdio.h>
#include <stdlib.h>

#include "plategen.h"
#include "stringutils.h"
#include "list.h"

#define CLS system("cls")
#define PAUSE system("pause")
#define flush fflush(stdin)
#define MAX_CHARACTERS 50

int main() {
    initRandomizer();

    List list;
    initList(&list, MAX_CHARACTERS);

    char result[MAX_CHARACTERS], format[MAX_CHARACTERS];
    char option;

    // I'm aware you gonna complain about the goto's but, fite me bro!

restart:
    if (list.size != 0) {
        clearList(&list);
    }
    CLS;
    puts("Write out your format with the parts that should be randomized as special characters.");
    puts("\t%c - If you want it to generate a random character.");
    puts("\t%d - If you want it to generate a random digit.\n");
    puts("Example: %c%c%c-%d%d%d -> ABC-123\n");
    printf("Enter a format: ");
    flush;

    getl(&list);

    if (list.size > MAX_CHARACTERS) {
        puts("To many characters! (max 50)");
        PAUSE;
        goto restart;
    }

    ltos(&list, format);

roll:
    generatePlate(format, result);
    printf("License plate: %s.\n", result);


option_menu:
    if (list.size != 0) {
        clearList(&list);
    }
    puts("Enter r to re-roll or x to restart: ");
    flush;

    getl(&list);

    if (list.size == 0) {
        puts("Please enter r or x first.");
        goto option_menu;
    }

    option = getFromList(&list, 0);

    if (option == 'r') {
        goto roll;
    }

    if (option == 'x') {
        goto restart;
    }

    puts("That's not an option... ");
    goto option_menu;
}
