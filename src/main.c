#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "logic.h"

void recur(int index, int varnum, int resnum, unsigned int* values, char* ops); 
void do_boolean(int varnum, int resnum, unsigned int* values, char* ops);

int main(int argc, char** argv) 
{ 
    if (argc != 2) { 
        fprintf(stderr, "Usage: ttable INPUT-FILE\n"); 
        exit(1);
    }
    
    FILE* input_file = fopen(argv[1], "r");

    char* symbols;
    char* ops;
    unsigned int* values;
    int varnum = readvars(input_file, &symbols, &values);
    int resnum = readops(input_file, &ops);
    //int resnum = 2; //temporary
                    
    fclose(input_file);

    display_symbols(varnum, symbols);
    recur(0, varnum, resnum, values, ops); 
    free(symbols);
    free(values);
    return 0;
}

void recur(int index, int varnum, int resnum, unsigned int* values, char* ops) {
   
    if (index == varnum - 1) {
        values[index] = 0;
        do_boolean(varnum, resnum, values, ops);
        display_values(varnum, resnum, values);
        values[index] = 1;
        do_boolean(varnum, resnum, values, ops);
        display_values(varnum, resnum, values);
        return;
    }
    else {
        values[index] = 0;
        //display_values(varnum, *values);
        recur(index + 1, varnum, resnum, values, ops);
        values[index] = 1;
        //display_values(varnum, *values);
        recur(index + 1, varnum, resnum, values, ops);
    }
}

void do_boolean(int varnum, int resnum, unsigned int* values, char* ops) {
    for (int i = 0; i < resnum; i++) {
       switch (ops[i]) {
           case 'o':
                values[varnum + i] = boolean_or(values[i], values[i+1]);
                break;
           case 'a':
                printf("A\n");
                values[varnum + i] = boolean_and(values[i], values[i+1]);
                break;
       }
    }

    //values[varnum + resnum - 2] = boolean_or(values[0], values[1]);
    //values[varnum + resnum - 1] = boolean_and(values[0], values[1]);
}
    
