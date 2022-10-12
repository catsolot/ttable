#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int SIZE = 100;

int readvars(FILE* input_file, char** symbols, unsigned int** values) {
    int varnum = 0;

    fscanf(input_file, "%d\n", &varnum);

    char* loc_symbols = calloc(varnum, sizeof(char));
    unsigned int* loc_values = calloc(varnum + varnum - 1, sizeof(unsigned int));

    for (int i = 0; i < varnum; i++) {
        fscanf(input_file, "%c ", &loc_symbols[i]);
        loc_values[i] = 0;
    }

    *symbols = loc_symbols;
    *values = loc_values;
    return varnum;
}

int readops(FILE* input_file, char** ops) {
    char buffer[SIZE];
    char loc_ops[SIZE]; 
    int index = 0;
    while ((fscanf(input_file, "%s ", buffer)) != EOF) {
        if (strcmp(buffer, "OR") == 0) {
            loc_ops[index] = 'o';
        }
        else if (strcmp(buffer, "AND") == 0) {
            loc_ops[index] = 'a';
        }
        printf("%c\n", loc_ops[index]);
        index++;
    }
    *ops = calloc(index + 1, sizeof(char));
    for (int i = 0; i < index; i++) {
        *ops[i] = loc_ops[i];
    }
    return index;
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

