#include <stdio.h>
#include <stdlib.h>

int readvars(FILE* input_file, char** symbols, unsigned int** values) {
    int varnum = 0;

    fscanf(input_file, "%d\n", &varnum);

    char* loc_symbols = calloc(varnum, sizeof(char));
    unsigned int* loc_values = calloc(varnum + 2, sizeof(unsigned int));
    for (int i = 0; i < varnum; i++) {
        fscanf(input_file, "%c ", &loc_symbols[i]);
        loc_values[i] = 0;
    }

    *symbols = loc_symbols;
    *values = loc_values;
    return varnum;
}

void display_symbols(int varnum, char* symbols) {
    printf("|");
    for (int i = 0; i < varnum; i++) {
        printf(" %c ", symbols[i]);
    }
    printf("| OR  | AND");
    printf("|\n");
}

void display_values(int varnum, int resnum, unsigned int* values) {
    printf("|");
    for (int i = 0; i < varnum; i++) {
        printf(" %d ", values[i]);
    }
    printf("|");
    for (int i = varnum; i < varnum + resnum; i++) {
        printf("  %d  ", values[i]);
    }
    printf("|\n");
}

