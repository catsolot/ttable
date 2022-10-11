#include <stdio.h>
#include <stdlib.h>

int readvars(FILE* input_file, char** symbols, unsigned int** values);
void display_symbols(int, char*);
void display_values(int varnum, int resnum, unsigned int* values); 
void recur(int index, int varnum, int resnum, unsigned int* values); 
void boolean_or(int varnum, int resnum, unsigned int* values); 


void inc(unsigned int* val); 

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
    int resnum = 1; //temporary
                    
    fclose(input_file);

    display_symbols(varnum, symbols);
    recur(0, varnum, resnum, values); 
    free(symbols);
    free(values);
    return 0;
}

void inc(unsigned int* val) {
    val[2] = 1;
}

int readvars(FILE* input_file, char** symbols, unsigned int** values) {
    int varnum = 0;

    fscanf(input_file, "%d\n", &varnum);

    char* loc_symbols = calloc(varnum, sizeof(char));
    unsigned int* loc_values = calloc(varnum + 1, sizeof(unsigned int));
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
    printf("|\n");
}

void display_values(int varnum, int resnum, unsigned int* values) {
    printf("|");
    for (int i = 0; i < varnum; i++) {
        printf(" %d ", values[i]);
    }
    printf("|");
    for (int i = varnum; i < varnum + resnum; i++) {
        printf(" %d ", values[i]);
    }
    printf("|\n");
}

//void display(int varnum, char** symbols, unsigned int** values) {
//
//}

void recur(int index, int varnum, int resnum, unsigned int* values) {
    if (index == varnum - 1) {
        values[index] = 0;
        boolean_or(varnum, resnum, values);
        display_values(varnum, resnum, values);
        values[index] = 1;
        boolean_or(varnum, resnum, values);
        display_values(varnum, resnum, values);
        return;
    }
    else {
        values[index] = 0;
        //display_values(varnum, *values);
        recur(index + 1, varnum, resnum, values);
        values[index] = 1;
        //display_values(varnum, *values);
        recur(index + 1, varnum, resnum, values);
    }
}

void boolean_or(int varnum, int resnum, unsigned int* values) {
    //unsigned int res = 0;
    for (int i = 0; i < varnum; i++) {
        //res = res + values[i];
        //if (res == 2) {
        if (values[i] == 1) {
            values[varnum + resnum - 1] = 1;
            return;
        }
    }
    values[varnum + resnum - 1] = 0;
}

