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
