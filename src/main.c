#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "logic.h"

void recur(int index, int varnum, int resnum, unsigned int* values); 


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
        do_boolean(varnum, resnum, values);
        //boolean_or(varnum, resnum - 1, values);
        //boolean_and(varnum, resnum, values);
        display_values(varnum, resnum, values);
        values[index] = 1;
        do_boolean(varnum, resnum, values);
        //boolean_or(varnum, resnum - 1, values);
        //boolean_and(varnum, resnum, values);
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

void do_boolean(int varnum, int resnum, unsigned int* values) {
    values[varnum + resnum - 2] = boolean_or(0, 1, values);
    values[varnum + resnum - 1] = boolean_and(0, 1, values);
}
    
