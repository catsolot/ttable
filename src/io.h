#include "boolvar.h"

int readvars(FILE* input_file, struct BoolVar** vars);
void display_symbols(int, char*);
void display_values(int varnum, int resnum, struct BoolVar* vars); 
int readops(FILE* input_file, struct BoolVar** vars);
