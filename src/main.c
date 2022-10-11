#include <stdio.h>
#include <stdlib.h>
#include "io.h"

void recur(int index, int varnum, int resnum, unsigned int* values); 
void boolean_or(int varnum, int resnum, unsigned int* values); 
void boolean_and(int varnum, int resnum, unsigned int* values); 


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
    int resnum = 2; //temporary
                    
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


//void display(int varnum, char** symbols, unsigned int** values) {
//
//}

void recur(int index, int varnum, int resnum, unsigned int* values) {
    if (index == varnum - 1) {
        values[index] = 0;
        boolean_or(varnum, resnum - 1, values);
        boolean_and(varnum, resnum, values);
        display_values(varnum, resnum, values);
        values[index] = 1;
        boolean_or(varnum, resnum - 1, values);
        boolean_and(varnum, resnum, values);
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
    for (int i = 0; i < varnum; i++) {
        if (values[i] == 1) {
            values[varnum + resnum - 1] = 1;
            return;
        }
    }
    values[varnum + resnum - 1] = 0;
}

void boolean_and(int varnum, int resnum, unsigned int* values) {
    for (int i = 0; i < varnum; i++) {
        if (values[i] == 0) {
            values[varnum + resnum - 1] = 0;
            return;
        }
    }
    values[varnum + resnum - 1] = 1;
}
