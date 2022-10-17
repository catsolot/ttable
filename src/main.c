#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "logic.h"

//void recur(int index, int varnum, int resnum, unsigned int* values, char* ops); 
void recur(int index, int varnum, int resnum, struct BoolVar* vars); 
void do_boolean(int varnum, int resnum, unsigned int* values, char* ops);

int main(int argc, char** argv) 
{ 
    if (argc != 2) { 
        fprintf(stderr, "Usage: ttable INPUT-FILE\n"); 
        exit(1);
    }
    
    FILE* input_file = fopen(argv[1], "r");

    struct BoolVar* vars;
    //char* symbols;
    char* ops;
    //unsigned int* values;
    int varnum = readvars(input_file, &vars);
    int resnum = readops(input_file, &ops);
    //int resnum = 2; //temporary
                    
    fclose(input_file);

    //display_symbols(varnum, symbols);
    recur(0, varnum, resnum, vars); 
    //free(symbols);
    //free(values);
    free(vars);
    return 0;
}

void recur(int index, int varnum, int resnum, struct BoolVar* vars) {
   
    if (index == varnum - 1) {
        vars[index].value = 0;
        //do_boolean(varnum, resnum, vars);
        display_values(varnum, resnum, vars);
        vars[index].value = 1;
        //do_boolean(varnum, resnum, values, ops);
        display_values(varnum, resnum, vars);
        return;
    }
    else {
        vars[index].value = 0;
        recur(index + 1, varnum, resnum, vars);
        vars[index].value = 1;
        recur(index + 1, varnum, resnum, vars);
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
    
