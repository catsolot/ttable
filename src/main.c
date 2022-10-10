#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int readvars(FILE* input_file, char** symbols, unsigned int** values);
int main(int argc, char** argv) 
{ 
    if (argc != 2) { 
        fprintf(stderr, "Usage: ttable INPUT-FILE\n"); 
        exit(1);
    }
    
    FILE* input_file = fopen(argv[1], "r");

    char* symbols;
    unsigned int* values;
    int varnum = readvars(input_file, &symbols, &values);
    for (int i = 0; i < varnum; i++) {
        printf("%c has value %d\n", symbols[i], values[i]);
    }
    fclose(input_file);
    return 0;
}

int readvars(FILE* input_file, char** symbols, unsigned int** values) {
    int varnum = 0;

    fscanf(input_file, "%d\n", &varnum);

    char* loc_symbols = calloc(varnum, sizeof(char));
    unsigned int* loc_values = calloc(varnum, sizeof(unsigned int));
    for (int i = 0; i < varnum; i++) {
        fscanf(input_file, " %c ", &loc_symbols[i]);
        loc_values[i] = 0;
    }

    *symbols = loc_symbols;
    *values = loc_values;
    return varnum;
}


