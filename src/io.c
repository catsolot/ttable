#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"

const int SIZE = 100;


int readvars(FILE* input_file, struct BoolVar** vars) {
    int varnum = 0;

    fscanf(input_file, "%d\n", &varnum);

    char* loc_symbols = calloc(varnum, sizeof(char));
    unsigned int* loc_values = calloc(varnum + varnum - 1, sizeof(unsigned int));
    struct BoolVar* loc_vars = calloc(varnum, sizeof(struct BoolVar));

    for (int i = 0; i < varnum; i++) {
        fscanf(input_file, "%c ", &loc_vars[i].symbol);
        loc_vars[i].value = 0;
    }
    
    *vars = loc_vars; 
    return varnum;
}

//int readops(FILE* input_file, char** ops) {
//    char buffer[SIZE];
//    char loc_ops[SIZE]; 
//    int index = 0;
//    while ((fscanf(input_file, "%s ", buffer)) != EOF) {
//        if (strcmp(buffer, "OR") == 0) {
//            loc_ops[index] = 'o';
//        }
//        else if (strcmp(buffer, "AND") == 0) {
//            loc_ops[index] = 'a';
//        }
//        printf("%c\n", loc_ops[index]);
//        index++;
//    }
//    *ops = calloc(index + 1, sizeof(char));
//    for (int i = 0; i < index; i++) {
//        *ops[i] = loc_ops[i];
//    }
//    return index;
//}
     
int readops(FILE* input_file, struct BoolVar** vars) {
    struct BoolVar* ptr = *vars;
    char buffer[SIZE];
    char loc_ops[SIZE]; 
    int index = 0;
    while ((fscanf(input_file, "%s ", buffer)) != EOF) {
        if (strcmp(buffer, "OR") == 0) {
            ptr[index]->symbol = 'o';
        }
        else if (strcmp(buffer, "AND") == 0) {
            ptr[index]->symbol = 'a';
        }
        printf("%c\n", ptr[index]->symbol);
        index++;
    }
    //*ops = calloc(index + 1, sizeof(char));
    //for (int i = 0; i < index; i++) {
    //    *ops[i] = loc_ops[i];
    //}
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

void display_values(int varnum, int resnum, struct BoolVar* vars) {
    printf("|");
    for (int i = 0; i < varnum; i++) {
        printf(" %d ", vars[i].value);
    }
    //printf("|");
    //for (int i = varnum; i < varnum + resnum; i++) {
    //    printf("  %d  ", values[i]);
    //}
    printf("|\n");
}

